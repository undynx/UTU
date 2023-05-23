/*CONSULTA 10
Para cada película (devolver su nombre), devolver la edad de la persona más joven
que participó en la misma y el nombre del trabajo que realizó. */
SELECT m1.name Pelicula, people.name Nombre, timestampdiff(YEAR, people.birthdate, curdate()) Edad, jobs.name  Trabajo_Realizado
FROM movies as m1 
	join casts on m1.id = casts.movie_id
	join people on casts.person_id = people.id
    join jobs on casts.job_id = jobs.id
WHERE timestampdiff(YEAR, people.birthdate, curdate()) <= (SELECT MIN(timestampdiff(YEAR, p2.birthdate, curdate()))
															FROM movies as m2 join casts as c2 on m2.id = c2.movie_id
																join people as p2 on c2.person_id = p2.id
															WHERE m1.name = m2.name)
ORDER BY m1.name;