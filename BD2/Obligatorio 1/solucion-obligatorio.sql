/*CONSULTA 1. 
Devolver nombre, duración, promedio de votos y año de estreno de todas las películas 
estrenadas a partir del primero de enero de 2011.  */
SELECT name, runtime, vote_average, date 
FROM movies
WHERE date > '2011-01-01';


/*CONSULTA 2. 
Devolver el nombre de las películas que fueron a pérdida y la cantidad que perdieron. 
Solo se deben considerar películas ya estrenadas. */
SELECT name, budget, revenue, date 
FROM movies
WHERE budget < revenue AND date < CURRENT_DATE
ORDER BY date desc;


/*CONSULTA 3. 
Devolver para cada saga su nombre y todos los géneros (nombre e identificador) que le 
corresponden. */
SELECT DISTINCT sagas.name, genres.name 
FROM sagas JOIN movie_in_saga as mins ON sagas.id = mins.saga_id
	JOIN movie_genres as mg ON mins.movie_id = mg.movie_id
	JOIN genres ON mg.genre_id = genres.id;
    
    
/* CONSULTA 4
Devolver identificador nombre y fecha de estreno de las películas que forman parte de
cada saga, en conjunto con el nombre de cada saga. Los datos devueltos deben estar
ordenados por nombre de saga y fecha de estreno de las películas. */
SELECT sagas.name, movies.id, movies.name, movies.date
FROM sagas JOIN movie_in_saga as mins ON sagas.id = mins.saga_id
	JOIN movies ON mins.movie_id = movies.id
ORDER BY sagas.name, movies.date;


/* CONSULTA 5
Devolver identificador, nombre y duración de cada saga. Se entiende que la duración
de cada saga es la suma de las duraciones de las películas que la conforman. */
SELECT sagas.id, sagas.name, SUM(movies.runtime) as Duracion
FROM sagas JOIN movie_in_saga as mins ON sagas.id = mins.saga_id
	JOIN movies ON mins.movie_id = movies.id
GROUP BY sagas.id
HAVING Duracion
ORDER BY Duracion;


/* CONSULTA 6
Devolver nombre del género del que existen más cantidad de películas.  */
SELECT genres.id as IDGenero, genres.name as NombreGenero, COUNT(*) as CantPeliculas
FROM genres JOIN movie_genres AS mg ON genres.id = mg.genre_id
GROUP BY genres.id
HAVING CantPeliculas >= ALL (SELECT COUNT(*)
	FROM genres JOIN movie_genres AS mg ON genres.id = mg.genre_id
	GROUP BY genres.id)
;