/* Tabla que guarda las inconsistencias */
CREATE TABLE inconsist_tot_pel (
	id_alerta serial, 
    id_pelicula bigint
);

/********************/
/* Trigger que guarda un log en inconsist_tot_pel cada vez que se inserta una pelicula */

delimiter //
CREATE TRIGGER tot_peliculas AFTER INSERT on movies
for each row
begin
	insert into inconsist_tot_pel (id_pelicula) values(NEW.id);
end //
delimiter ;

/********************/
/* Trigger que elimina el log de inconsist_tot_pel cuando se agrega el idioma
de alguna pelicula que esté en la tabla */

delimiter //
CREATE TRIGGER tot_peliculas_borrar AFTER INSERT on movie_languages
for each row
begin
	DELETE FROM inconsist_tot_pel as itp
    WHERE NEW.movie_id = itp.id_pelicula;
end //
delimiter ;

