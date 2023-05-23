/*CONSULTA 2. 
Devolver el nombre de las películas que fueron a pérdida y la cantidad que perdieron. 
Solo se deben considerar películas ya estrenadas. */
SELECT name, budget, revenue, date 
FROM movies
WHERE budget < revenue AND date < CURRENT_DATE
ORDER BY date desc;