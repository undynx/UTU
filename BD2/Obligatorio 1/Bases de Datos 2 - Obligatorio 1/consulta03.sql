/*CONSULTA 3. 
Devolver para cada saga su nombre y todos los géneros (nombre e identificador) que le 
corresponden. */
SELECT DISTINCT sagas.name, genres.name 
FROM sagas JOIN movie_in_saga as mins ON sagas.id = mins.saga_id
	JOIN movie_genres as mg ON mins.movie_id = mg.movie_id
	JOIN genres ON mg.genre_id = genres.id;