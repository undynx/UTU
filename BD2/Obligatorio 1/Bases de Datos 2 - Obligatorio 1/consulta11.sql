/* CONSULTA 11. 
Devolver el nombre de todas las mujeres que participaron en una única película en el 
año 2015. Se debe retornar además el nombre de la película en la que participaron y el 
trabajo que hicieron en la misma */
SELECT people.name as NombreActriz, movies.name as nombrePeli, jobs.name as TrabajoRealizado 
FROM people JOIN casts ON people.id = casts.person_id
	JOIN jobs ON casts.job_id = jobs.id
	JOIN movies ON casts.movie_id = movies.id
WHERE YEAR(movies.date) = '2015'  AND people.gender = 1
GROUP BY people.name, movies.name, jobs.name
HAVING COUNT(*) = 1;