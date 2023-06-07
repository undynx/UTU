/* TO DO: 
	* Preguntarle al profe por qué al disparar una signal no se inserta en la tabla inconsist_r3
    * Hacer el trigger para cuando se hace un update
*/

CREATE TABLE inconsist_r3(
	id_sucursal int,
    id_personal int
);

drop trigger r3_encargados
delimiter //
CREATE TRIGGER r3_encargados AFTER INSERT on sucursales
for each row
begin
	DECLARE idPersonalExists int default(null);
    DECLARE errorMessage varchar(255);
    DECLARE errorSignal boolean default(false);
    
	IF NEW.idEncargado IS NOT NULL THEN
		SELECT idPersonal INTO idPersonalExists
        FROM personal
        WHERE idPersonal = NEW.idEncargado
			and activo = true;
            
		IF idPersonalExists IS NULL THEN
			INSERT INTO inconsist_r3 values(NEW.idSucursal, NEW.idEncargado);
            SET errorSignal = true;
		END IF;
        
        IF errorSignal = true THEN
			SET errorMessage = CONCAT('Error: No se puede agregar el encargado ', CAST(NEW.idEncargado AS CHAR), ' a la sucursal ', CAST(NEW.idSucursal AS CHAR), ' porque no existe un empleado activo con ese id');
			SIGNAL sqlstate '45000' SET message_text = errorMessage;
		END IF;
	END IF;
end //

insert into sucursales values(8, 454, 'P. Sherman Calle Wallaby', 300, null, 12345678);

select * from sucursales;
select * from personal;
select * from inconsist_r3;