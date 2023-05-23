/* CONSULTA 8.
Devolver para cada saga, los actores que participaron de todas sus películas */
SELECT p.id, p.name
FROM people AS p INNER JOIN (
    SELECT mc.person_id, mis.saga_id, COUNT(DISTINCT mis.movie_id) AS num_movies
    FROM movie_in_saga AS mis INNER JOIN casts AS mc ON mis.movie_id = mc.movie_id
    WHERE mc.job_id = (SELECT id FROM jobs WHERE name = 'Actor')
    GROUP BY mc.person_id, mis.saga_id
    HAVING COUNT(DISTINCT mis.movie_id) = (
        SELECT COUNT(DISTINCT mis2.movie_id)
        FROM movie_in_saga AS mis2
        WHERE mis2.saga_id = mis.saga_id
    )
) AS q ON p.id = q.person_id
ORDER BY q.saga_id, p.name;