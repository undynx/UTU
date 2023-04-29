-- -----------------------------------------------------
-- Schema bd2gr24
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `bd2gr24` DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci ;
USE `bd2gr24` ;

-- -----------------------------------------------------
-- Table `bd2gr24`.`companias`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `bd2gr24`.`companias` (
  `nombreComp` CHAR(10) NOT NULL,
  `ciudadComp` CHAR(10) NOT NULL)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `bd2gr24`.`companias2`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `bd2gr24`.`companias2` (
  `nombreComp` CHAR(10) NOT NULL,
  `ciudadComp` CHAR(10) NOT NULL)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `bd2gr24`.`gerencia`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `bd2gr24`.`gerencia` (
  `nombreEmp` CHAR(10) NOT NULL,
  `nombreGerente` CHAR(10) NULL DEFAULT NULL,
  PRIMARY KEY (`nombreEmp`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `bd2gr24`.`trabaja`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `bd2gr24`.`trabaja` (
  `nombreEmp` CHAR(10) NOT NULL,
  `nombreComp` CHAR(10) NULL DEFAULT NULL,
  `salario` INT NULL DEFAULT NULL,
  PRIMARY KEY (`nombreEmp`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;


-- -----------------------------------------------------
-- Table `bd2gr24`.`vive`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `bd2gr24`.`vive` (
  `nombre` CHAR(10) NOT NULL,
  `direccion` CHAR(10) NULL DEFAULT NULL,
  `ciudad` CHAR(10) NULL DEFAULT NULL,
  PRIMARY KEY (`nombre`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_0900_ai_ci;

insert into companias values('INCA', 'MONTEVIDEO');
insert into companias values('INCA', 'MALDONADO');
insert into companias values('INCA', 'LASPIEDRAS');
insert into companias values('INCA', 'SALINAS');
insert into companias values('FARM.SA', 'MONTEVIDEO');
insert into companias values('FARM.SA', 'MALDONADO');
insert into companias values('FARM.SA', 'LASPIEDRAS');
insert into companias values('HLP.SA', 'MONTEVIDEO');
insert into companias values('HLP.SA', 'MONTEVIDEO');
insert into companias values('HLP.SA', 'LA PAZ');
insert into companias values('RAMF.LTDA', 'TACUAREMBO');
insert into companias values('AMIP', 'FLORIDA');

insert into bd2gr24.companias2 values('FARM.SA', 'MONTEVIDEO');
insert into bd2gr24.companias2 values('FARM.SA', 'MALDONADO');
insert into bd2gr24.companias2 values('FARM.SA', 'LASPIEDRAS');

insert into bd2gr24.gerencia values('Jose', 'Ruben');
insert into bd2gr24.gerencia values('Juan', 'Ruben');
insert into bd2gr24.gerencia values('Gonzalo', 'Pedro');

insert into bd2gr24.trabaja values('Jose', 'INCA', 100);
insert into bd2gr24.trabaja values('Juan', 'INCA', 100);
insert into bd2gr24.trabaja values('Ruben', 'INCA', 150);
insert into bd2gr24.trabaja values('Maité', 'HLP.SA', 900000);
insert into bd2gr24.trabaja values('Gonzalo', 'HLP.SA', 300);
insert into bd2gr24.trabaja values('Pedro', 'HLP.SA', 500);
insert into bd2gr24.trabaja values('Ana', 'AMIP', 800);

insert into bd2gr24.vive values('Jose', 'dir 2', 'MALDONADO');
insert into bd2gr24.vive values('Juan', 'dir 1', 'MONTEVIDEO');
insert into bd2gr24.vive values('Ruben', 'dir 3', 'MONTEVIDEO');
insert into bd2gr24.vive values('Maité', 'dir 4', 'LA PAZ');
insert into bd2gr24.vive values('Gonzalo', 'dir 5', 'TACUAREMBO');
insert into bd2gr24.vive values('Pedro', 'dir 6', 'TACUAREMBO');
insert into bd2gr24.vive values('Ana', 'dir 7', 'CANELONES');