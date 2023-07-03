/*Implementar un trigger para impedir cualquier borrado en la tabla IMPUESTOS.*/
create schema parcial;

create table Impuestos(
nombre varchar(20),
id smallint primary key,
valor smallint
);
    
insert into Impuestos values("Ejemplo1", 1, 10);
insert into Impuestos values("Ejemplo2", 2, 20);
insert into Impuestos values("Ejemplo3", 3, 30);

delimiter //
CREATE TRIGGER Impuestos_AD after delete on Impuestos
FOR EACH ROW
BEGIN
	SIGNAL sqlstate '45001' SET message_text = "Delete no permitido";
END
//

delete from Impuestos WHERE valor = 10;

/*****************************************/

/*Se quiere auditar ciertos cambios en la tabla ARTICULOS, 
para ello se pide implementar un trigger que: 
a. Registre cualquier Alta o Eliminación de registros 
b. Registre cualquier cambio en algún Precio (Compra o Venta) 

En todos los casos deberá registrar dichos cambios en una tabla llamada AUDIT_ARTICULOS, y la información a almacenar por cada registro modificado deberá ser: 
 idArt 
 Operación (N = Nuevo artículo, E = articulo eliminado, M = modificación de precio) 
 PrecioCompraAnterior (si corresponde, sino grabar NULL) 
 PrecioCompraPosterior (si corresponde, sino grabar NULL) 
 PrecioVentaAnterior (si corresponde, sino grabar NULL) 
 PrecioVentaPosterior (si corresponde, sino grabar NULL) 
 Usuario que hizo la modificación 
 Fecha y Hora de la modificación

Además asegúrese que no se puedan eliminar tuplas en AUDIT_ARTICULOS. */

CREATE TABLE AUDIT_ARTICULOS(
	idArt tinyint,
    operacion enum('N', 'E', 'M'),
    precioCompraAnterior decimal(7,2),
    precioCompraPosterior decimal(7,2),
    precioVentaAnterior decimal(7,2),
	precioVentaPosterior decimal(7,2),
	usuario char(30),
    fechayHora timestamp
);

delimiter //
CREATE TRIGGER Articulos_AI after insert on articulos 
FOR EACH ROW
BEGIN

	INSERT INTO audit_articulos values(
		NEW.idArt,
        'N',
        NULL,
        NEW.PrecioCompra,
        NULL, 
        NEW.PrecioVenta,
        current_user(),
        now()
	);
END;
//

delimiter //
CREATE TRIGGER Articulos_AD after delete on articulos 
FOR EACH ROW
BEGIN
	INSERT INTO audit_articulos values(
		OLD.idArt,
        'E',
        OLD.PrecioCompra,
        NULL,
        OLD.PrecioVenta,
        NULL, 
        current_user(),
        now()
	);
END;
//

drop trigger Articulos_AU
delimiter //
CREATE TRIGGER Articulos_AU after update on articulos 
FOR EACH ROW
BEGIN
	INSERT INTO audit_articulos values(
		OLD.idArt,
        'M',
        OLD.PrecioCompra,
        NEW.PrecioCompra,
        OLD.PrecioVenta,
        NEW.PrecioVenta, 
        current_user(),
        now()
	);
END;
//

INSERT INTO articulos values(48, 'Juguetito', 150, 300, 8, 11);
DELETE FROM articulos WHERE idArt = 48;
UPDATE articulos SET PrecioCompra = 900 WHERE idArt = 1

select * from audit_articulos;
select * from articulos;


-- EJERCICIO 3
/* A efectos de mantener la consistencia en las facturas se solicita implementar 
un trigger para mantener consistente el campo Importe en VENTAS_CABEZAL con su 
correspondiente detalle en VENTAS_DETALLE. 
Este trigger deberá activarse con cualquier evento en la tabla VENTAS_DETALLE 
Se sugiere implementarlo en 2 etapas: primero asumir que solo se dispara para 
una factura, y luego que se dispara para N facturas. */
DROP TRIGGER VentasDetalle_AI;

delimiter //
CREATE TRIGGER VentasDetalle_AI after insert on VENTAS_DETALLE
FOR EACH ROW 
BEGIN
	DECLARE precioNuevo int;
    
    SELECT (a.PrecioVenta * NEW.Cantidad) into precioNuevo
    FROM ARTICULOS as A
    WHERE A.idArt = NEW.idArt;
    
    UPDATE VENTAS_CABEZAL
    SET Importe = Importe + precioNuevo
    WHERE NroFactura = NEW.NroFactura;
    
END
//

delimiter //
CREATE TRIGGER VentasDetalle_AD after delete on VENTAS_DETALLE
FOR EACH ROW 
BEGIN
    DECLARE precioArticulo int;
    
    SELECT a.PrecioVenta into precioArticulo
    FROM ARTICULOS as A
    WHERE A.idArt = OLD.idArt;
    
    UPDATE VENTAS_CABEZAL
    SET Importe = Importe - precioArticulo
    WHERE NroFactura = OLD.NroFactura;
    
END
//

delimiter //
CREATE TRIGGER VentasDetalle_AU after update on VENTAS_DETALLE
FOR EACH ROW 
BEGIN
    DECLARE precioAnterior int;
    DECLARE precioActual int;
    
    SELECT (a.PrecioVenta * OLD.cantidad) into precioAnterior
    FROM ARTICULOS as A
    WHERE A.idArt = OLD.idArt;
    
    SELECT (a.precioVenta * NEW.cantidad) into precioActual
    FROM ARTICULOS as A
    WHERE A.idArt = NEW.idArt;
    
    UPDATE VENTAS_CABEZAL
    SET Importe = Importe - precioAnterior + precioActual
    WHERE NroFactura = NEW.NroFactura;
    
END
//

select * from ventas_detalle;
select * from ventas_cabezal;
select * from articulos;

DELETE FROM ventas_detalle WHERE NroFactura = 1 and idArt = 8


-- EJERCICIO 4
/* Luego de implementar los triggers de los ejercicios (2) y (3) 
modifique el trigger del ejercicio (2) para que además recalcule los 
Importes de VENTAS_CABEZAL cuando se modifique un Precio de Venta.*/

drop trigger Articulos_AU;

delimiter //
CREATE TRIGGER Articulos_AU after update on Articulos
FOR EACH ROW
BEGIN
	
    DECLARE cNFact tinyint;
    DECLARE cidArt tinyint;
    DECLARE cCantidad tinyint;
	DECLARE precioAnterior int;
    DECLARE precioNuevo int;
    DECLARE finDatos int default 0;
    DECLARE cur CURSOR 
		FOR SELECT NroFactura, idArt, Cantidad
        FROM ventas_detalle
        WHERE idArt = NEW.idArt;
	DECLARE CONTINUE HANDLER FOR SQLSTATE '02000' SET finDatos = 1;
    
    INSERT INTO audit_articulos values(
			NEW.idArt,
            'M',
            OLD.precioCompra,
            NEW.precioCompra,
            OLD.precioVenta,
            NEW.precioVenta, 
            current_user(),
            now()
		);
    
    OPEN cur;
    FETCH cur INTO cNFact, cidArt, cCantidad;
    WHILE finDatos = 0 DO
		
        SET precioAnterior = OLD.PrecioVenta * cCantidad;
        SET precioNuevo = NEW.PrecioVenta * cCantidad;
        
        UPDATE VENTAS_CABEZAL
        SET Importe = Importe - precioAnterior + precioNuevo
        WHERE NroFactura = cNFact;
        
        FETCH cur INTO cNFact, cidArt, cCantidad;
    
    END WHILE;
    CLOSE cur;
END;
//

select * from ventas_cabezal;
select * from ventas_detalle;
select * from articulos;

update articulos set precioVenta = 7000 where idArt = 11;