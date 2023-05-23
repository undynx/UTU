/* CONSULTA 5
Devolver identificador, nombre y duración de cada saga. Se entiende que la duración
de cada saga es la suma de las duraciones de las películas que la conforman. */
SELECT sagas.id, sagas.name, SUM(movies.runtime) as Duracion
FROM sagas JOIN movie_in_saga as mins ON sagas.id = mins.saga_id
	JOIN movies ON mins.movie_id = movies.id
GROUP BY sagas.id
HAVING Duracion
ORDER BY Duracion;