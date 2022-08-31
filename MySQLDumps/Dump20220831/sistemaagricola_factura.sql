-- MySQL dump 10.13  Distrib 8.0.30, for Win64 (x86_64)
--
-- Host: localhost    Database: sistemaagricola
-- ------------------------------------------------------
-- Server version	8.0.30

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `factura`
--

DROP TABLE IF EXISTS `factura`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `factura` (
  `idorden` int NOT NULL AUTO_INCREMENT,
  `idcliente` int NOT NULL,
  `idprod` varchar(3) NOT NULL,
  `areaprod` int NOT NULL,
  `cantidad` int NOT NULL,
  `fecha` datetime NOT NULL,
  PRIMARY KEY (`idorden`),
  KEY `fk_idprod_factura` (`idprod`),
  KEY `fk_idarea_factura_idx` (`areaprod`),
  CONSTRAINT `fk_idarea_factura` FOREIGN KEY (`areaprod`) REFERENCES `area` (`idarea`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `fk_idprod_factura` FOREIGN KEY (`idprod`) REFERENCES `producto` (`idproducto`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=29 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `factura`
--

LOCK TABLES `factura` WRITE;
/*!40000 ALTER TABLE `factura` DISABLE KEYS */;
INSERT INTO `factura` VALUES (1,100967581,'2B',3,6,'2022-08-30 00:00:00'),(2,118120871,'2A',5,3,'2022-08-30 00:00:00'),(22,118120871,'3F',2,8,'2022-08-30 00:00:00'),(23,117459908,'4H',9,3,'2022-08-31 00:00:00'),(24,107868890,'3C',4,15,'2022-08-30 00:00:00'),(25,12345678,'4B',1,5,'2022-08-31 00:00:00'),(26,298745631,'4H',7,3,'2022-08-31 00:00:00'),(27,298745631,'2B',8,7,'2022-08-31 00:00:00'),(28,298745631,'8A',2,12,'2022-08-31 00:00:00');
/*!40000 ALTER TABLE `factura` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2022-08-31 12:22:27
