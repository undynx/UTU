delimiter //
CREATE PROCEDURE balance_cliente (in id_cliente int, in fechaConsulta timestamp, out saldo decimal(5,2))
BEGIN
	DECLARE finDatos int default(0);
	DECLARE costoTotal decimal(5,2) default(0);
    DECLARE duracionReal int default(0);
    DECLARE cidPelicula int;
    DECLARE cidCliente int;
    DECLARE cFechaAlquiler timestamp;
    DECLARE duracAlquiler int;
    DECLARE costAlquiler decimal (4,2);
    DECLARE costReemplazo decimal (5,2);
    DECLARE duracionCobrar int;
    
    -- seleccionamos a los usuarios que alquilaron antes de la fecha
    -- pasada por parametro y que NO pagaron aun
    DECLARE cur CURSOR
    FOR SELECT al.idPelicula, al.idCliente, al.fecha
    FROM alquileres as al
    WHERE al.idCliente = id_cliente
		AND TIMESTAMPDIFF(day, al.fecha, fechaConsulta) > 0
        AND ((TIMESTAMPDIFF(day, fechaConsulta, al.fechaDevolucion) > 0) OR (al.fechaDevolucion is NULL));
	DECLARE CONTINUE HANDLER FOR SQLSTATE '02000' SET finDatos = 1;
    
    OPEN cur;
    FETCH cur INTO cidPelicula, cidCliente, cFechaAlquiler;
    
    WHILE finDatos = 0 DO
		SET duracionReal = TIMESTAMPDIFF(day, cFechaAlquiler, fechaConsulta);
		
		SELECT p.duracionAlquiler, p.costoAlquiler, p.costoReemplazo INTO duracAlquiler, costAlquiler, costReemplazo 
			FROM peliculas p 
			WHERE p.idPelicula = cidPelicula;
		
        IF duracionReal <= duracAlquiler THEN
			SET costoTotal = costoTotal + costAlquiler;
		ELSEIF duracionReal > (duracAlquiler * 3) THEN
			SET costoTotal = costoTotal + costReemplazo;
		ELSE 
			SET duracionCobrar = duracionReal - duracAlquiler;
			SET costoTotal = costoTotal + costAlquiler + 5.00 * duracionCobrar;
		END IF;
        
		FETCH cur INTO cidPelicula, cidCliente, cFechaAlquiler;
    END WHILE;
    CLOSE cur;
    SET saldo = costoTotal;
END;
//