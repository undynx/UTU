/* Ranking de ventas por familia, esto es listar en orden descendente 
de importes los totales de importes vendidos por Familia de artículos. 
Incluir anulaciones. */

SELECT F.idFam, SUM(A.PrecioVenta * VD.Cantidad) as Sumita
FROM (ARTICULOS as A join FAMILIAS as F on A.idFam = F.idFam)
	join VENTAS_DETALLE as VD on A.idArt = VD.idArt
WHERE VD.NroFactura NOT IN (SELECT NroFacturaAnula
							FROM VENTAS_CABEZAL)
GROUP BY F.idFam
ORDER BY Sumita DESC;



/* Facturas con más de 3 artículos diferentes y por un monto superior a 5.000 $. 
Excluir las anulaciones.  */

SELECT NroFactura, COUNT(NroFactura) as Cuentita
FROM VENTAS_DETALLE 
WHERE NroFactura NOT IN(SELECT NroFacturaAnula
						FROM VENTAS_CABEZAL)
	and NroFactura NOT IN(SELECT NroFactura
						FROM VENTAS_CABEZAL
                        WHERE Importe <= 5000)
GROUP BY NroFactura 
HAVING Cuentita > 3;



/* Una lista conteniendo el Día del mes y el importe de factura más alto 
por cada día, para el mes actual. Excluir las anulaciones.  */
SELECT day(Fecha), MAX(Importe)
FROM VENTAS_CABEZAL
WHERE NroFactura NOT IN(SELECT NroFacturaAnula
						FROM VENTAS_CABEZAL)
GROUP BY day(Fecha)



/* ¿Cuáles facturas del mes actual no han sido anuladas?  */
SELECT NroFactura
FROM VENTAS_CABEZAL
WHERE month(Fecha) = month(now()) 
	and NroFactura NOT IN(SELECT NroFacturaAnula
							FROM VENTAS_CABEZAL)



/* Artículos que nunca fueron vendidos  */
SELECT idArt, Nombre
FROM ARTICULOS
WHERE idArt NOT IN (SELECT DISTINCT idArt
					FROM VENTAS_DETALLE)



/* Listar las facturas de un periodo dado (d1 a d2) incluyendo: 
Nº de Factura, Nombre del Cliente, Fecha, Importe (sin impuestos), Importe de Impuestos */
SELECT VC.NroFactura, P.Nombre, VC.Fecha, VC.Importe as ImporteSinImpuestos, VC.Importe * (I.Porcentaje/100) as Impuestos, VC.Importe + (VC.Importe * (I.Porcentaje/100)) as ImporteConImpuestos
FROM ((VENTAS_CABEZAL as VC join PERSONAS as P on VC.idPersona = P.idPersona)
		join VENTAS_IMPUESTOS as VI on VC.NroFactura = VI.NroFactura)
        join IMPUESTOS as I on VI.idImpuesto = I.idImpuesto;



/* Una consulta que devuelva personas que sean Cliente y Proveedor a la vez*/
SELECT C.idPersona
FROM CLIENTES as C
WHERE C.idPersona IN (SELECT P.idPersona
					FROM PROVEEDORES as P);



/* Facturas de artículos inexistentes  */
SELECT NroFactura
FROM VENTAS_DETALLE
WHERE idArt NOT IN (SELECT idArt
					FROM ARTICULOS);



/* Personas que no son ni Clientes ni Proveedores. */
SELECT idPersona
FROM PERSONAS
WHERE idPersona NOT IN (SELECT idPersona
						FROM CLIENTES)
and idPersona NOT IN (SELECT idPersona
					FROM PROVEEDORES);



/* Anulaciones de facturas que no existen  */
SELECT DISTINCT NroFacturaAnula
FROM VENTAS_CABEZAL
WHERE NroFacturaAnula NOT IN (SELECT NroFactura
							FROM VENTAS_CABEZAL)