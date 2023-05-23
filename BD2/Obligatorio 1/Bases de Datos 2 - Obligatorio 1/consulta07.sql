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