-- EJERCICIO 1
/* Implemente un Stored Procedure llamado AltaPersona que solicite todos los datos 
de la persona (excepto el id que será generado automáticamente) y un parámetro extra 
que indique si es Cliente o Proveedor. Tener en cuenta que se deberán solicitar además 
algunos datos propios de Cliente o Proveedor. 
Este SP deberá darlo de alta en la(s) tabla(s) que corresponda(n). 
Debe emitir un mensaje a la salida standard indicando el nuevo Id generado. */

ALTER TABLE Personas AUTO_INCREMENT=112;
select * from personas;
insert into personas(Nombre, TipoDoc, Documento, Direccion) values('Mei', 2, 112211-2, 'Dir 5')

delimiter //
CREATE PROCEDURE AltaPersona(in inNombre varchar(18), in inTipoDoc tinyint, in inDocumento varchar(9), 
in inDireccion varchar(5), in inTipo enum('C', 'P'),  in inCiudad varchar(10), in inContacto varchar(10), out outIdPersona smallint)
	BEGIN
    
		DECLARE nuevoId smallint;
		INSERT INTO personas(Nombre, TipoDoc, Documento, Direccion) values (inNombre, inTipoDoc, inDocumento, inDireccion);
        SET nuevoId = (SELECT last_insert_id() FROM Personas LIMIT 1);
		
		IF inTipo = 'C' THEN
			INSERT INTO Clientes values (nuevoId, inCiudad);
		ELSE
			INSERT INTO Proveedores values (nuevoId, inContacto);
		END IF;
        SET outIdPersona = nuevoId;
		SELECT nuevoId;
	END;
//

call AltaPersona('Maite', 2, '1122', 'Dir 3', 'C', 'Mvd', '19236555', @salida);
SELECT @salida


/*EJERCICIO 2 SP
Ejercicio 2 
Implemente un Stored Procedure llamado ImprimirArticulo que 
recibe como parámetro un id. de Articulo e imprime sus datos 
en el siguiente formato : 
Id. : 1 
Nombre : xxxxxxxxxxxxxxxx 
Precio de Compra : NNN 
Precio de Venta : NNN 
Margen de ganancia : XX % 
Cantidad en Stock : N unidades 
Familia : CodFamilia - NombreFamilia 
Margen de ganancia = 100 * ((Precio de Venta / Precio de Compra ) - 1) 
Si el id pasado por parametro no existiera no hacer nada y retornar (-1) en un parámetro de salida.

Se sugiere la salida generarla en la tabla: SalidaSP (id, texto) */

Create table salidaSP (id int not null auto_increment primary key, texto varchar(80) );