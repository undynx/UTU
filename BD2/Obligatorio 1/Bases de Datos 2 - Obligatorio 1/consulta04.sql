/* CONSULTA 4
Devolver identificador nombre y fecha de estreno de las películas que forman parte de
cada saga, en conjunto con el nombre de cada saga. Los datos devueltos deben estar
ordenados por nombre de saga y fecha de estreno de las películas. */
SELECT sagas.name, movies.id, movies.name, movies.date
FROM sagas JOIN movie_in_saga as mins ON sagas.id = mins.saga_id
	JOIN movies ON mins.movie_id = movies.id
ORDER BY sagas.name, movies.date;