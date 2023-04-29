-- MySQL dump 10.16  Distrib 10.1.26-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: db
-- ------------------------------------------------------
-- Server version	10.1.26-MariaDB-0+deb9u1
-- drop database bd2_UTU;
create database BD2_UTU;
use BD2_UTU;
/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `ARTICULOS`
--

DROP TABLE IF EXISTS `ARTICULOS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `ARTICULOS` (
  `idArt` tinyint(4) DEFAULT NULL,
  `Nombre` varchar(34) DEFAULT NULL,
  `PrecioCompra` decimal(7,2) DEFAULT NULL,
  `PrecioVenta` decimal(7,2) DEFAULT NULL,
  `Stock` tinyint(4) DEFAULT NULL,
  `idFam` tinyint(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `ARTICULOS`
--

LOCK TABLES `ARTICULOS` WRITE;
/*!40000 ALTER TABLE `ARTICULOS` DISABLE KEYS */;
INSERT INTO `ARTICULOS` VALUES (1,'MP3 mod. AX100',800.00,1200.00,10,22),(2,'MP4 AKIO-SM200',1100.00,1500.00,8,22),(3,'Reloj Kasio',1000.00,1600.00,20,22),(4,'Celular quintuple SIM',5000.00,7800.00,50,22),(5,'Celular con Guindous',6000.00,8500.00,12,22),(6,'Licuadora JTronic mod. 3000',2500.00,3750.00,5,11),(7,'Tostadora JTronic 1000 W',1200.00,1800.00,15,11),(8,'Radiador 7 paneles ACME',1200.00,1860.00,20,11),(9,'MP3 mod. AX100',800.00,1200.00,10,11),(10,'Tostadora JTronic 2000 W (4 tost.)',2100.00,3120.00,10,11),(11,'Lavarropa ACME Mod. 2019',5200.00,6850.00,30,11),(12,'Lavavajilla ACME mod. TNX101',6000.00,7920.00,14,11),(13,'TV LCD 22´´',7000.00,8900.00,10,33),(14,'TV LCD 33´´',10000.00,12000.00,20,33),(15,'TV LCD 40´´',12000.00,16000.00,8,33),(16,'TV PLASMA 50´´',30000.00,38000.00,5,33),(17,'TV LED 40´´',50000.00,60000.00,6,33),(18,'EQUIPO AUDIO ZONI 400W',4000.00,6000.00,14,33),(19,'EQUIPO AUDIO ZONI 1500W',6000.00,7800.00,16,33),(20,'Microcomponentes AIGUA 4000',5100.00,6780.00,18,33);
/*!40000 ALTER TABLE `ARTICULOS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `CLIENTES`
--

DROP TABLE IF EXISTS `CLIENTES`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `CLIENTES` (
  `idPersona` smallint(6) DEFAULT NULL,
  `Ciudad` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `CLIENTES`
--

LOCK TABLES `CLIENTES` WRITE;
/*!40000 ALTER TABLE `CLIENTES` DISABLE KEYS */;
INSERT INTO `CLIENTES` VALUES (100,'Montevideo'),(103,'Canelones'),(105,'Maldonado'),(110,'Montevideo'),(104,'Salto'),(108,'Florida'),(106,'Canelones'),(111,'Montevideo');
/*!40000 ALTER TABLE `CLIENTES` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `FAMILIAS`
--

DROP TABLE IF EXISTS `FAMILIAS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `FAMILIAS` (
  `idFam` tinyint(4) DEFAULT NULL,
  `Nombre` varchar(21) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `FAMILIAS`
--

LOCK TABLES `FAMILIAS` WRITE;
/*!40000 ALTER TABLE `FAMILIAS` DISABLE KEYS */;
INSERT INTO `FAMILIAS` VALUES (11,'Electrodomesticos'),(22,'Electronicos pequeños'),(33,'Electronicos grandes'),(44,'Muebleria'),(55,'Bazar (cocina-baño)');
/*!40000 ALTER TABLE `FAMILIAS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `IMPUESTOS`
--

DROP TABLE IF EXISTS `IMPUESTOS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `IMPUESTOS` (
  `idImpuesto` tinyint(4) DEFAULT NULL,
  `Nombre` varchar(13) DEFAULT NULL,
  `Porcentaje` decimal(5,3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `IMPUESTOS`
--

LOCK TABLES `IMPUESTOS` WRITE;
/*!40000 ALTER TABLE `IMPUESTOS` DISABLE KEYS */;
INSERT INTO `IMPUESTOS` VALUES (1,'IVA Compras',22.000),(2,'IVA Ventas',22.000),(3,'Por las dudas',20.000);
/*!40000 ALTER TABLE `IMPUESTOS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PERSONAS`
--

DROP TABLE IF EXISTS `PERSONAS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PERSONAS` (
  `idPersona` smallint(6) DEFAULT NULL,
  `Nombre` varchar(18) DEFAULT NULL,
  `TipoDoc` tinyint(4) DEFAULT NULL,
  `Documento` varchar(9) DEFAULT NULL,
  `Direccion` varchar(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PERSONAS`
--

LOCK TABLES `PERSONAS` WRITE;
/*!40000 ALTER TABLE `PERSONAS` DISABLE KEYS */;
INSERT INTO `PERSONAS` VALUES (100,'Juan Perez',1,'1111222-4','Dir1'),(101,'Ana Perez',2,'1111222-4','Dir2'),(102,'Julian Martinez',1,'1111222-4','Dir3'),(103,'Leandro Gutierrez',2,'1111222-4','Dir4'),(104,'Lucia Miraballes',1,'1111222-4','Dir1'),(105,'Roberto Mendez',1,'1111222-4','Dir5'),(106,'Sebastian Piñeyrua',1,'1111222-4','Dir6'),(107,'Soledad Giménez',3,'1111222-4','Dir26'),(112,'Sandra García',1,'1111222-4','Dir1'),(108,'Jorge Ubaldía',1,'1111222-4','Dir67'),(110,'Damian Lopez',4,'1111222-4','Dir12'),(111,'Rosana Zarate',3,'1111222-4','Dir14');
/*!40000 ALTER TABLE `PERSONAS` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `PROVEEDORES`
--

DROP TABLE IF EXISTS `PROVEEDORES`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `PROVEEDORES` (
  `idPersona` smallint(6) DEFAULT NULL,
  `Contacto` varchar(10) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `PROVEEDORES`
--

LOCK TABLES `PROVEEDORES` WRITE;
/*!40000 ALTER TABLE `PROVEEDORES` DISABLE KEYS */;
INSERT INTO `PROVEEDORES` VALUES (101,'Contacto 1'),(102,'Contacto 2'),(107,'Contacto 3'),(109,'Contacto 4'),(112,'Contacto 5'),(100,'Contacto 7');
/*!40000 ALTER TABLE `PROVEEDORES` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `TIPOS_DOC`
--

DROP TABLE IF EXISTS `TIPOS_DOC`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `TIPOS_DOC` (
  `TipoDoc` tinyint(4) DEFAULT NULL,
  `Nombre` varchar(15) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `TIPOS_DOC`
--

LOCK TABLES `TIPOS_DOC` WRITE;
/*!40000 ALTER TABLE `TIPOS_DOC` DISABLE KEYS */;
INSERT INTO `TIPOS_DOC` VALUES (1,'CI Uruguaya'),(2,'RUC'),(3,'DNI (ARG)'),(40,'Doc. Extranjero');
/*!40000 ALTER TABLE `TIPOS_DOC` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `VENTAS_CABEZAL`
--

DROP TABLE IF EXISTS `VENTAS_CABEZAL`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `VENTAS_CABEZAL` (
  `NroFactura` tinyint(4) DEFAULT NULL,
  `idPersona` smallint(6) DEFAULT NULL,
  `Fecha` varchar(19) DEFAULT NULL,
  `Importe` decimal(8,2) DEFAULT NULL,
  `NroFacturaAnula` varchar(2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `VENTAS_CABEZAL`
--

LOCK TABLES `VENTAS_CABEZAL` WRITE;
/*!40000 ALTER TABLE `VENTAS_CABEZAL` DISABLE KEYS */;
INSERT INTO `VENTAS_CABEZAL` VALUES (1,106,'2019-01-03 00:00:00',12000.00,''),(2,103,'2019-01-03 00:00:00',28220.00,''),(3,104,'2019-02-03 00:00:00',13560.00,''),(4,106,'2019-02-03 00:00:00',62400.00,''),(5,100,'2019-02-04 00:00:00',224850.00,''),(6,108,'2019-04-04 00:00:00',42580.00,''),(7,103,'2019-02-05 00:00:00',2400.00,''),(8,104,'2019-02-05 00:00:00',92000.00,''),(9,105,'2019-03-06 00:00:00',5400.00,''),(10,100,'2019-03-03 00:00:00',3750.00,''),(11,110,'2019-05-04 00:00:00',37200.00,''),(12,111,'2019-05-04 00:00:00',55800.00,''),(13,111,'2019-05-04 00:00:00',3720.00,''),(14,106,'2019-05-03 00:00:00',6850.00,''),(15,105,'2019-05-05 00:00:00',15840.00,''),(16,105,'2019-05-05 00:00:00',8900.00,''),(17,103,'2019-05-05 00:00:00',20170.00,''),(18,100,'2019-05-05 00:00:00',46400.00,''),(19,100,'2019-05-05 00:00:00',-15840.00,'15'),(20,100,'2019-05-06 00:00:00',-3720.00,'13');
/*!40000 ALTER TABLE `VENTAS_CABEZAL` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `VENTAS_DETALLE`
--

DROP TABLE IF EXISTS `VENTAS_DETALLE`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `VENTAS_DETALLE` (
  `NroFactura` tinyint(4) DEFAULT NULL,
  `idArt` tinyint(4) DEFAULT NULL,
  `Cantidad` tinyint(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `VENTAS_DETALLE`
--

LOCK TABLES `VENTAS_DETALLE` WRITE;
/*!40000 ALTER TABLE `VENTAS_DETALLE` DISABLE KEYS */;
INSERT INTO `VENTAS_DETALLE` VALUES (1,1,10),(1,45,1),(2,2,1),(2,3,2),(2,10,5),(2,12,1),(3,20,2),(4,19,8),(5,17,3),(5,16,1),(5,11,1),(6,1,2),(6,20,1),(6,11,4),(6,18,1),(7,1,2),(8,1,10),(8,15,5),(9,7,3),(10,6,1),(11,8,20),(12,8,30),(13,8,2),(14,11,1),(15,12,2),(16,13,1),(17,1,1),(17,9,1),(17,10,1),(17,11,1),(17,19,1),(18,1,2),(18,3,5),(18,14,3),(20,8,-2),(19,12,-2),(44,1,1);
/*!40000 ALTER TABLE `VENTAS_DETALLE` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `VENTAS_IMPUESTOS`
--

DROP TABLE IF EXISTS `VENTAS_IMPUESTOS`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `VENTAS_IMPUESTOS` (
  `NroFactura` tinyint(4) DEFAULT NULL,
  `idImpuesto` tinyint(4) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `VENTAS_IMPUESTOS`
--

LOCK TABLES `VENTAS_IMPUESTOS` WRITE;
/*!40000 ALTER TABLE `VENTAS_IMPUESTOS` DISABLE KEYS */;
INSERT INTO `VENTAS_IMPUESTOS` VALUES (1,2),(2,2),(3,2),(4,3),(5,2),(6,2),(7,2),(8,3),(10,2),(11,2),(13,2),(14,2),(15,2),(16,2),(17,2),(18,2),(19,2),(20,2);
/*!40000 ALTER TABLE `VENTAS_IMPUESTOS` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-08-22 15:20:27
