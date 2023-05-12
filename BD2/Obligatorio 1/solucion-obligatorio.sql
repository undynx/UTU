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

/* CONSULTA 7
Devolver todos los tipos de referencias entre películas de una saga.  */
SELECT referenciada.id AS Referenciada_id, referenciada.name AS Referencia_A, referencia.id AS Referencia_id, referencia.name AS Referenciada_Por, mr.type AS Tipo_de_referencia, sagas.name AS De_la_Saga
FROM movie_references AS mr 
	JOIN movies AS referencia ON referencia.id = mr.reference_to
	JOIN movies AS referenciada ON mr.referenced_by = referenciada.id
    JOIN movie_in_saga AS mis ON referencia.id = mis.movie_id
    JOIN movie_in_saga AS mis2 ON mis2.movie_id = referenciada.id
    JOIN sagas ON mis.saga_id = sagas.id
WHERE mis.saga_id = mis2.saga_id AND referencia.id <> referenciada.id;


/* CONSULTA 8.
Devolver para cada saga, los actores que participaron de todas sus películas */
SELECT p.id, p.name
FROM people AS p
INNER JOIN (
    SELECT mc.person_id, mis.saga_id, COUNT(DISTINCT mis.movie_id) AS num_movies
    FROM movie_in_saga AS mis
    INNER JOIN casts AS mc ON mis.movie_id = mc.movie_id
    WHERE mc.job_id = (SELECT id FROM jobs WHERE name = 'Actor')
    GROUP BY mc.person_id, mis.saga_id
    HAVING COUNT(DISTINCT mis.movie_id) = (
        SELECT COUNT(DISTINCT mis2.movie_id)
        FROM movie_in_saga AS mis2
        WHERE mis2.saga_id = mis.saga_id
    )
) AS q ON p.id = q.person_id
ORDER BY q.saga_id, p.name;


/* CONSULTA 9.
Devolver la edad de todas las personas que participaron en alguna película, en
conjunto con el nombre de la película de la que participaron, para las películas con más
de 8 personas en su elenco. */


/*CONSULTA 10.
Para cada película (devolver su nombre), devolver la edad de la persona más joven
que participó en la misma y el nombre del trabajo que realizó.*/
SELECT movies.name, people.name, (CURDATE() - people.birthdate) Edad
	FROM movies 
		JOIN casts ON movies.id = casts.movie_id 
		JOIN people ON casts.person_id = people.id
GROUP BY movies.id
HAVING (CURDATE() - people.birthdate) <= ALL (SELECT (CURDATE() - p2.birthdate) Edad
	FROM movies m2
		JOIN casts c2 ON m2.id = c2.movie_id 
		JOIN people p2 ON c2.person_id = p2.id
		GROUP BY m2.id)
;


/* CONSULTA 11. 
Devolver el nombre de todas las mujeres que participaron en una única película en el 
año 2015. Se debe retornar además el nombre de la película en la que participaron y el 
trabajo que hicieron en la misma */
SELECT people.name as NombreActriz, movies.name as nombrePeli, jobs.name as TrabajoRealizado FROM
	people 
		JOIN casts ON people.id = casts.person_id
        JOIN jobs ON casts.job_id = jobs.id
        JOIN movies ON casts.movie_id = movies.id
        WHERE 
			YEAR(movies.date) = '2015'  
            AND people.gender = 1
		GROUP BY people.name, movies.name, jobs.name
        HAVING COUNT(*) = 1;