CREATE TABLE inconsist_r3(
	id_sucursal int,
    id_personal int
);

delimiter //
CREATE PROCEDURE insertInconsistencia(in id_sucursal int, in id_personal int)
BEGIN
	insert into inconsist_r3 VALUES(id_sucursal, id_personal);
END;
//

delimiter //
CREATE TRIGGER r3_encargados_AI AFTER INSERT on sucursales
for each row
begin
	DECLARE idPersonalExists int default(null);
    DECLARE errorMessage varchar(255);
    
	IF NEW.idEncargado IS NOT NULL THEN
		SELECT idPersonal INTO idPersonalExists
        FROM personal
        WHERE idPersonal = NEW.idEncargado
			and activo = true;
            
		IF idPersonalExists IS NULL THEN
			CALL insertInconsistencia(NEW.idSucursal, NEW.idEncargado);
			SET errorMessage = CONCAT('Error: No se puede agregar el encargado ', CAST(NEW.idEncargado AS CHAR), ' a la sucursal ', CAST(NEW.idSucursal AS CHAR), ' porque no existe un empleado activo con ese id');
			SIGNAL sqlstate '45000' SET message_text = errorMessage;
		END IF;
	END IF;
end //

delimiter //
CREATE TRIGGER r3_encargados_AU AFTER UPDATE on sucursales
for each row
begin
	DECLARE idPersonalExists int default(null);
    DECLARE errorMessage varchar(255);
    
	IF NEW.idEncargado IS NOT NULL THEN
		SELECT idPersonal INTO idPersonalExists
        FROM personal
        WHERE idPersonal = NEW.idEncargado
			and activo = true;
            
		IF idPersonalExists IS NULL THEN
			CALL insertInconsistencia(NEW.idSucursal, NEW.idEncargado);
			SET errorMessage = CONCAT('Error: No se puede modificar el encargado ', CAST(NEW.idEncargado AS CHAR), ' en la sucursal ', CAST(NEW.idSucursal AS CHAR), ' porque no existe un empleado activo con ese id');
			SIGNAL sqlstate '45000' SET message_text = errorMessage;
		END IF;
	END IF;
end //
