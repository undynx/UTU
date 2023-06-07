/* Tabla que guarda las inconsistencias */
CREATE TABLE inconsist_tot_pel (
	id_alerta serial, 
    id_pelicula int
);

/********************/
/* Trigger que guarda un log en inconsist_tot_pel cada vez que se inserta una pelicula */

delimiter //
CREATE TRIGGER tot_peliculas AFTER INSERT on peliculas
for each row
begin
	insert into inconsist_tot_pel (id_pelicula) values(NEW.idPelicula);
end //
delimiter ;

/********************/
/* Trigger que elimina el log de inconsist_tot_pel cuando se agrega el idioma
de alguna pelicula que esté en la tabla */

delimiter //
CREATE TRIGGER tot_peliculas_borrar AFTER INSERT on idiomasDePeliculas
for each row
begin
	DELETE FROM inconsist_tot_pel as itp
    WHERE NEW.idPelicula = itp.id_pelicula;
end //
delimiter ;

