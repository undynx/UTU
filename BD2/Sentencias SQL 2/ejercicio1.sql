-- Nombre y ciudad donde viven las personas 
-- que trabajan en la compañia de nombre INCA.

select nombre, ciudad
from vive join trabaja on nombre = nombreEmp
where nombrecomp = 'INCA';

-- Nombre, dirección y ciudad de las personas que trabajan 
--en la compañia de nombre HLP.SA y ganan más de $800.000

select nombre, direccion, ciudad
from vive join trabaja on nombre = nombreEmp
where nombreComp = 'HLP.SA' and salario > 80000;

-- Nombre y dirección de las personas que viven en la misma ciudad 
-- en la cual está ubicada la compañía para la cual trabaja 
-- o viven en la misma ciudad que su gerente.

(select distinct nombre, direccion
from (vive join trabaja on nombre = nombreEmp)
		natural join companias
where ciudad = ciudadComp)
UNION
select v1.nombre, v1.direccion
from (vive as v1 join gerencia on v1.nombre = nombreEmp)
		join vive as v2 on nombreGerente = v2.nombre
where v1.ciudad = v2.ciudad;

-- Nombre de las personas que no trabajan para la compañía AMIP.
select nombreEmp 
from trabaja
where nombreComp != 'AMIP';

-- Nombre y dirección de las personas que viven en la 
-- misma ciudad que su gerente y que no viven en la ciudad 
-- de la compañía RAMF.LTDA
select v1.nombre, v1.direccion
from (vive as v1 join gerencia on v1.nombre = nombreEmp)
		join vive as v2 on v2.nombre = nombreGerente
where v1.ciudad = v2.ciudad 
and v1.nombre not in (select nombre
						from vive
                        where ciudad = (select ciudadComp
										from companias
                                        where nombreComp = 'RAMF.LTDA'));

select * from trabaja;
select * from vive;
select * from companias;
select * from gerencia;