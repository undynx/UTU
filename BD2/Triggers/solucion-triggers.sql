/*EJERCICIO 1
Implementar un trigger para impedir cualquier borrado en la tabla IMPUESTOS.*/
create table Impuestos(
nombre varchar(20),
id smallint primary key,
smallint
);
    
insert into Impuestos values("Ejemplo1", 1, 10);
insert into Impuestos values("Ejemplo2", 2, 20);
insert into Impuestos values("Ejemplo3", 3, 30);

delimiter //
CREATE TRIGGER Impuestos_AD after delete on Impuestos
	for each row
    begin
		SIGNAL sqlstate '45001' set message_text = "Delete no permitido en la tabla Impuestos";
	end//

DELETE FROM Impuestos 
WHERE id = 1;


/*EJERCICIO 2
Se quiere auditar ciertos cambios en la tabla ARTICULOS, 
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

Además asegúrese que no se puedan eliminar tuplas en AUDIT_ARTICULOS.*/


-- Agrega una tupla cuando se inserta algo nuevo en Articulos
delimiter //
CREATE TRIGGER Articulos_AI after insert on Articulos
for each row
begin
	insert into AuditArticulos(idArt, Operacion, PrecioCompraAnterior, PrecioCompraPosterior, PrecioVentaAnterior, PrecioVentaPosterior, Usuario, FechayHora) 
    values (NEW.idArt, 'I', NULL, NEW.PrecioCompra, NULL, NEW.PrecioVenta, current_user(), now());
end//

-- Agrega una tupla cuando se elimina algo en Articulos
delimiter //
CREATE TRIGGER Articulos_AD after delete on Articulos
for each row
begin
	insert into AuditArticulos(idArt, Operacion, PrecioCompraAnterior, PrecioCompraPosterior, PrecioVentaAnterior, PrecioVentaPosterior, Usuario, FechayHora) 
    values (OLD.idArt, 'D', OLD.PrecioCompra, NULL, OLD.PrecioVenta, NULL, current_user(), now());
end//

-- Agrega una tupla cuando se modifica algo en Articulos
delimiter //
CREATE TRIGGER Articulos_AU after update on Articulos
for each row
begin
	insert into AuditArticulos(idArt, Operacion, PrecioCompraAnterior, PrecioCompraPosterior, PrecioVentaAnterior, PrecioVentaPosterior, Usuario, FechayHora) 
    values (NEW.idArt, 'M', OLD.PrecioCompra, NEW.PrecioCompra, OLD.PrecioVenta, NEW.PrecioVenta, current_user(), now());
end//

-- No permite que se eliminen cosas en la tabla AuditArticulos
delimiter //
CREATE TRIGGER AuditArticulos_AD after delete on AuditArticulos
	for each row
    begin
		SIGNAL sqlstate '45001' set message_text = "Delete no permitido en la tabla AuditArticulos";
end//