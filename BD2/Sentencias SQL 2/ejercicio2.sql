-- Obtener el código, el nombre y la duración de las tareas que 
-- se deben realizar inmediatamente antes de la tarea con código "c42".
SELECT codT, nomT, duracion
FROM tareas JOIN PREVIAS on codT = codTP
WHERE codTS = 'c42';


-- Obtener los nombres y año de ingreso de los funcionarios que 
-- tienen algún sueldo mayor que algún sueldo del funcionario con número 812.
SELECT DISTINCT f.nroF, f.aaIng
FROM funcionarios f JOIN trabaja t on t.nroF = f.nroF
WHERE t.nrof != 812 and
			t.sueldo > (SELECT MIN(sueldo) 
									FROM trabaja 
									WHERE nroF = 812);


-- Obtener las parejas de números de funcionarios tales que 
-- el primero tiene asignada una tarea que debe realizarse inmediatamente 
-- antes que una tarea asignada al segundo funcionario.
SELECT f1.nroF, f2.nroF
FROM (ASIGNACION as f1 join PREVIAS on f1.codT = codTP)
	join ASIGNACION as f2 on f2.codT = codTS


-- Obtener los nombres de los funcionarios tales que en la 
-- misma fecha le asignaron más de una tarea
SELECT nomF
FROM funcionarios as F JOIN asignacion as A on F.nroF = A.nroF
GROUP BY nombF, fAsign
HAVING count(*) > 1