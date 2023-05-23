/* CONSULTA 6
Devolver nombre del género del que existen más cantidad de películas.  */
SELECT genres.id as IDGenero, genres.name as NombreGenero, COUNT(*) as CantPeliculas
FROM genres JOIN movie_genres AS mg ON genres.id = mg.genre_id
GROUP BY genres.id
HAVING CantPeliculas >= ALL (SELECT COUNT(*)
	FROM genres JOIN movie_genres AS mg ON genres.id = mg.genre_id
	GROUP BY genres.id);