/* CONSULTA 9.
Devolver la edad de todas las personas que participaron en alguna película, en
conjunto con el nombre de la película de la que participaron, para las películas con más
de 8 personas en su elenco. */
SELECT DISTINCT movies.name Pelicula, people.name Nombre, timestampdiff(YEAR, people.birthdate, curdate()) as Edad
FROM casts 
	JOIN movies ON casts.movie_id = movies.id
	JOIN people ON casts.person_id = people.id
WHERE (SELECT COUNT(*) 
		FROM casts c2
        WHERE c2.movie_id = movies.id) > 8
ORDER BY movies.name;