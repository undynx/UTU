/*CONSULTA 1. 
Devolver nombre, duración, promedio de votos y año de estreno de todas las películas 
estrenadas a partir del primero de enero de 2011.  */
SELECT name, runtime, vote_average, date 
FROM movies
WHERE date > '2011-01-01';