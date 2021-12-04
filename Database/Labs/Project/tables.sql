CREATE TABLE address(
    zip int PRIMARY KEY,
    street varchar NOT NULL,
    city varchar NOT NULL
);
INSERT INTO address VALUES (00030,'Abai St','Shymkent');
INSERT INTO address VALUES (00020,'Gagarin St','Nur-Sultan');
INSERT INTO address VALUES (00010,'Aliya St','Almaty');
INSERT INTO address VALUES (00040,'Monshuk St','Taraz');
INSERT INTO address VALUES (00050,'Zhubanov St','Otrar');
INSERT INTO address VALUES (00060,'Ablai-Khan St','Almaty');
INSERT INTO address VALUES (00070,'Kenesary St','Almaty');
INSERT INTO address VALUES (00080,'Chingiz St','Oral');
INSERT INTO address VALUES (00090,'Nazarbayev St','Uralsk');
INSERT INTO address VALUES (00100,'Tokaev St','Ust-Kamenogorsk');
INSERT INTO address VALUES (00110,'Mamin St','Kostanai');
INSERT INTO address VALUES (00120,'Choi St','Atyrau');
INSERT INTO address VALUES (00130,'Satpaev St','Aktau');
INSERT INTO address VALUES (00140,'Al-Farabi St','Ust-Kamenogorsk');
INSERT INTO address VALUES (00150,'Abulkhair St','Kostanai');
INSERT INTO address VALUES (00160,'Dariga St','Atyrau');
INSERT INTO address VALUES (00170,'Golovkin St','Aktau');
INSERT INTO address VALUES (00180,'Gogol St','Ust-Kamenogorsk');
INSERT INTO address VALUES (00190,'Tole-Bi St','Kostanai');
INSERT INTO address VALUES (00200,'Aiteke St','Atyrau');
INSERT INTO address VALUES (00201,'Panfilov St','Aktau');
INSERT INTO address VALUES (00202,'Kazybek-Bi St','Aktau');


CREATE TABLE auto_company(
    CO_ID varchar(30) PRIMARY KEY,
    name varchar(50) NOT NULL,
    founded_date date NOT NULL,
    zip int NOT NULL,
    FOREIGN KEY (zip) REFERENCES address(zip)
);

INSERT INTO auto_company VALUES (1, 'VOLKSWAGEN AUTO GROUP', '1937-05-28', 00030);

CREATE TABLE brands(
    BIN varchar(30) PRIMARY KEY,
    founded_date date NOT NULL,
    CO_ID varchar(30) NOT NULL,
    FOREIGN KEY (CO_ID) REFERENCES auto_company(CO_ID) ON DELETE SET NULL
);

INSERT INTO brands VALUES ('Audi', '1909-01-01', 1);
INSERT INTO brands VALUES ('Lamborghini', '1963-01-01', 1);
INSERT INTO brands VALUES ('Bugatti', '1909-01-01', 1);
INSERT INTO brands VALUES ('Bentley Motors', '1919-01-01', 1);
INSERT INTO brands VALUES ('Skoda Auto', '1895-12-18', 1);
INSERT INTO brands VALUES ('Porsche', '1931-01-01', 1);


CREATE TABLE factory(
    FACT_IN varchar(30) PRIMARY KEY,
    name varchar(50) NOT NULL,
    license boolean NOT NULL,
    budget integer DEFAULT 0,
    mistakes_percent numeric(3,2) DEFAULT 0.0,
    pollution_rate numeric(3,2) DEFAULT 0.0,
    cardinality int DEFAULT 0,
    CO_ID varchar(30) NOT NULL,
    zip int NOT NULL,
    FOREIGN KEY (CO_ID) REFERENCES auto_company(CO_ID) ON DELETE SET NULL,
    FOREIGN KEY (zip) REFERENCES address(zip)
);
INSERT INTO factory VALUES (1,'VOLKSWAGEN AG',TRUE, 100, 2.00, 1.00, 98, 1, 00020);
INSERT INTO factory VALUES (2,'VOLKSWAGEN AG',TRUE, 110, 1.00, 2.00, 97, 1, 00040);
INSERT INTO factory VALUES (3,'VOLKSWAGEN AG',TRUE, 90, 0, 4.00, 50.00, 1, 00050);

CREATE TABLE works_on(
    BIN varchar(30),
    FACT_IN varchar(30),
    PRIMARY KEY (BIN,FACT_IN),
    FOREIGN KEY (BIN) REFERENCES brands(BIN) ON DELETE CASCADE,
    FOREIGN KEY (FACT_IN) REFERENCES factory(FACT_IN) ON DELETE CASCADE
);

INSERT INTO works_on VALUES ('Audi',1);
INSERT INTO works_on VALUES ('Lamborghini',1);
INSERT INTO works_on VALUES ('Bugatti',2);
INSERT INTO works_on VALUES ('Bentley Motors',2);
INSERT INTO works_on VALUES ('Skoda Auto',3);
INSERT INTO works_on VALUES ('Porsche',3);

CREATE TABLE model_parts_factory(
    FACT_IN varchar(30) PRIMARY KEY,
    workers int DEFAULT 0,
    FOREIGN KEY (FACT_IN) REFERENCES factory(FACT_IN) ON DELETE CASCADE
);

INSERT INTO model_parts_factory VALUES (1, 62268);

CREATE TABLE final_assembly_factory(
    FACT_IN varchar(30) PRIMARY KEY,
    assembly_type varchar(10) NOT NULL,
    effectiveness int DEFAULT 100,
    FOREIGN KEY (FACT_IN) REFERENCES factory(FACT_IN) ON DELETE CASCADE
);

INSERT INTO final_assembly_factory VALUES (2, 9113);
INSERT INTO final_assembly_factory VALUES (3, 7179);


CREATE TABLE supplier(
    SUPP_IN varchar(30) PRIMARY KEY,
    name varchar(30) NOT NULL,
    supp_type varchar(20) NOT NULL,
    bankruptcy boolean DEFAULT FALSE,
    zip int NOT NULL,
    FOREIGN KEY (zip) REFERENCES address(zip)
);
INSERT INTO supplier VALUES(009, 'Parts', 'Engine', FALSE, 00060);

CREATE TABLE part(
    PART_IN varchar(30) PRIMARY KEY,
    error boolean DEFAULT FALSE,
    manufactured_date date DEFAULT now(),
    SUPP_IN varchar(30) DEFAULT NULL,
    FACT_IN varchar(30) DEFAULT NULL,
    FOREIGN KEY (SUPP_IN) REFERENCES supplier(SUPP_IN),
    FOREIGN KEY (FACT_IN) REFERENCES model_parts_factory(FACT_IN)
);
--engine
INSERT INTO part VALUES(1,FALSE,'2021-01-01', NULL,1);
INSERT INTO part VALUES(2,FALSE,'2021-01-02', NULL,1);
INSERT INTO part VALUES(3,FALSE,'2021-01-03', NULL,1);
--transmission
INSERT INTO part VALUES(4,FALSE,'2021-01-04', NULL,1);
INSERT INTO part VALUES(5,FALSE,'2021-01-05', 9,NULL);
INSERT INTO part VALUES(6,FALSE,'2021-01-06', 9,NULL);
INSERT INTO part VALUES(7,FALSE,'2021-01-07', 9,NULL);
INSERT INTO part VALUES(8,FALSE,'2021-01-08', 9,NULL);
INSERT INTO part VALUES(9,FALSE,'2021-01-09', 9,NULL);
INSERT INTO part VALUES(10,FALSE,'2021-01-10', 9,NULL);
INSERT INTO part VALUES(11,FALSE,'2021-01-11', 9,NULL);
INSERT INTO part VALUES(12,FALSE,'2021-01-12', 9,NULL);
INSERT INTO part VALUES(13,FALSE,'2021-01-13', 9,NULL);
INSERT INTO part VALUES(14,FALSE,'2021-01-14', 9,NULL);
INSERT INTO part VALUES(15,FALSE,'2021-01-15', 9,NULL);
INSERT INTO part VALUES(16,FALSE,'2021-01-16', 9,NULL);
INSERT INTO part VALUES(17,FALSE,'2021-01-17', 9,NULL);
INSERT INTO part VALUES(18,FALSE,'2021-01-18', 9,NULL);
INSERT INTO part VALUES(19,FALSE,'2021-01-19', 9,NULL);
INSERT INTO part VALUES(20,FALSE,'2021-01-20', 9,NULL);
INSERT INTO part VALUES(21,FALSE,'2021-01-21', 9,NULL);
INSERT INTO part VALUES(22,FALSE,'2021-01-22', 9,NULL);
INSERT INTO part VALUES(23,FALSE,'2021-01-23', 9,NULL);
INSERT INTO part VALUES(24,FALSE,'2021-01-24', 9,NULL);



CREATE TABLE dealers(
    DEAL_IN varchar(30) PRIMARY KEY,
    agreement boolean DEFAULT FALSE,
    country varchar(50) NOT NULL,
    service_type varchar(50)
);
INSERT INTO dealers VALUES (1,TRUE,'Kazakhstan','Sell');
INSERT INTO dealers VALUES (2,TRUE,'Kazakhstan','Sell');
INSERT INTO dealers VALUES (3,TRUE,'Kazakhstan','Sell');

CREATE TABLE inventory(
    PARK_IN varchar(30) PRIMARY KEY,
    park_slots int NOT NULL,
    electr_power boolean NOT NULL,
    start_date date NOT NULL,
    DEAL_IN varchar(30) DEFAULT NULL,
    zip int NOT NULL,
    FOREIGN KEY (DEAL_IN) REFERENCES dealers(DEAL_IN),
    FOREIGN KEY (zip) REFERENCES address(zip)
);
INSERT INTO inventory VALUES (1,30,FALSE,'2020-09-01',1,00070);
INSERT INTO inventory VALUES (2,50,TRUE,'2020-08-01',2,00080);
INSERT INTO inventory VALUES (3,20,TRUE,'2020-01-01',3,00090);


CREATE TABLE models(
    MOD_IN varchar(30) PRIMARY KEY ,
    model_title varchar(30) NOT NULL,
    release_year int NOT NULL,
    capacity int NOT NULL,
    door_num int NOT NULL,
    size varchar(7) NOT NULL,
    BIN varchar(30) NOT NULL,
    FOREIGN KEY (BIN) REFERENCES brands(BIN)
);

INSERT INTO models VALUES (1,'Convertible 1.0',2002,4,4,'Middle','Audi');
INSERT INTO models VALUES (2,'Convertible 1.0',2001,4,4,'Small','Lamborghini');
INSERT INTO models VALUES (3,'Convertible',2000,2,2,'Small','Audi');
INSERT INTO models VALUES (4,'Convertible 2.0',2002,4,4,'Large','Bugatti');
INSERT INTO models VALUES (5,'Convertible 3.0',2003,2,2,'Small','Bentley Motors');
INSERT INTO models VALUES (6,'Convertible 4.0',2004,1,2,'Small','Skoda Auto');
INSERT INTO models VALUES (7,'Truck 1.0',2010,4,4,'Middle','Porsche');
INSERT INTO models VALUES (8,'Truck 5.0',2007,4,4,'Large','Bugatti');
INSERT INTO models VALUES (9,'Sedan 1.0',2008,4,4,'Small','Lamborghini');
INSERT INTO models VALUES (10,'Sedan 3.0',2001,4,4,'Middle','Bentley Motors');

CREATE TABLE Convertible(
    MOD_IN varchar(30) PRIMARY KEY,
    roof boolean NOT NULL,
    FOREIGN KEY (MOD_IN) REFERENCES models(MOD_IN)
);
INSERT INTO Convertible VALUES(1,True);
INSERT INTO Convertible VALUES(2,False);
INSERT INTO Convertible VALUES(3,True);
INSERT INTO Convertible VALUES(4,False);
INSERT INTO Convertible VALUES(5,True);
INSERT INTO Convertible VALUES(6,True);

CREATE TABLE Sedan(
    MOD_IN varchar(30) PRIMARY KEY,
    slopy_back boolean NOT NULL,
    FOREIGN KEY (MOD_IN) REFERENCES models(MOD_IN)
);
INSERT INTO Sedan VALUES (9,True);
INSERT INTO Sedan VALUES (10,FALSE);


CREATE TABLE Truck(
    MOD_IN varchar(30) PRIMARY KEY,
    cargo_bed boolean NOT NULL,
    FOREIGN KEY (MOD_IN) REFERENCES models(MOD_IN)
);
INSERT INTO Truck VALUES (7,True);
INSERT INTO Truck VALUES (8,False);


CREATE TABLE vehicle(
    VIN varchar(30) PRIMARY KEY,
    manufactured date NOT NULL,
    country varchar(50) NOT NULL,
    certified boolean NOT NULL,
    PARK_IN varchar(30) NOT NULL,
    MOD_IN varchar(30) NOT NULL,
    FOREIGN KEY (PARK_IN) REFERENCES inventory(PARK_IN),
    FOREIGN KEY (MOD_IN) REFERENCES models(MOD_IN)
);
INSERT INTO vehicle VALUES (1,'2020-01-01','Kazakhstan',True,1,1);
INSERT INTO vehicle VALUES (2,'2020-01-02','Kazakhstan',True,3,2);
INSERT INTO vehicle VALUES (3,'2020-01-03','Kazakhstan',True,1,3);
INSERT INTO vehicle VALUES (4,'2020-01-04','Kazakhstan',True,3,4);
INSERT INTO vehicle VALUES (5,'2020-01-05','Kazakhstan',True,1,5);
INSERT INTO vehicle VALUES (6,'2020-01-06','Kazakhstan',True,3,6);
INSERT INTO vehicle VALUES (7,'2020-01-07','Kazakhstan',True,1,7);
INSERT INTO vehicle VALUES (8,'2020-01-08','Kazakhstan',True,3,8);
INSERT INTO vehicle VALUES (9,'2020-01-09','Kazakhstan',True,1,9);
INSERT INTO vehicle VALUES (10,'2020-01-10','Kazakhstan',True,3,10);
INSERT INTO vehicle VALUES (11,'2020-01-11','Kazakhstan',True,3,1);
INSERT INTO vehicle VALUES (12,'2020-01-12','Kazakhstan',True,1,2);
INSERT INTO vehicle VALUES (13,'2020-01-13','Kazakhstan',True,3,3);
INSERT INTO vehicle VALUES (14,'2020-01-14','Kazakhstan',True,1,4);
INSERT INTO vehicle VALUES (15,'2020-01-15','Kazakhstan',True,3,5);
INSERT INTO vehicle VALUES (16,'2020-01-16','Kazakhstan',True,2,6);
INSERT INTO vehicle VALUES (17,'2020-01-17','Kazakhstan',True,2,7);
INSERT INTO vehicle VALUES (18,'2020-01-18','Kazakhstan',True,2,8);
INSERT INTO vehicle VALUES (19,'2020-01-19','Kazakhstan',True,2,9);
INSERT INTO vehicle VALUES (20,'2020-01-20','Kazakhstan',True,2,10);

CREATE TABLE options(
    VIN varchar(30) PRIMARY KEY,
    colours varchar(30) NOT NULL,
    engine varchar(30) NOT NULL,
    transmission varchar(30) NOT NULL,
    FOREIGN KEY (VIN) REFERENCES vehicle(VIN),
    FOREIGN KEY (engine) REFERENCES part(PART_IN),
    FOREIGN KEY (transmission) REFERENCES part(PART_IN)
);
INSERT INTO options VALUES (1,'Red',1,4);
INSERT INTO options VALUES (2,'Blue',2,5);
INSERT INTO options VALUES (3,'White',3,6);
INSERT INTO options VALUES (4,'Pink',1,7);
INSERT INTO options VALUES (5,'Purple',2,8);
INSERT INTO options VALUES (6,'Black',3,9);
INSERT INTO options VALUES (7,'Grey',1,10);
INSERT INTO options VALUES (8,'Orange',2,11);
INSERT INTO options VALUES (9,'Yellow',3,12);
INSERT INTO options VALUES (10,'Pink',1,13);
INSERT INTO options VALUES (11,'Red',2,14);
INSERT INTO options VALUES (12,'Grey',3,15);
INSERT INTO options VALUES (13,'Black',1,16);
INSERT INTO options VALUES (14,'Orange',2,17);
INSERT INTO options VALUES (15,'Violet',3,18);
INSERT INTO options VALUES (16,'Blue',1,19);
INSERT INTO options VALUES (17,'Black',2,20);
INSERT INTO options VALUES (18,'Blue',3,21);
INSERT INTO options VALUES (19,'White',1,22);
INSERT INTO options VALUES (20,'White',2,23);


CREATE TABLE customers(
    IIN varchar(30) PRIMARY KEY,
    zip int NOT NULL,
    FOREIGN KEY (zip) REFERENCES address(zip)
);
INSERT INTO customers VALUES (1,00100);
INSERT INTO customers VALUES (2,00120);
INSERT INTO customers VALUES (3,00130);
INSERT INTO customers VALUES (4,00140);
INSERT INTO customers VALUES (5,00150);
INSERT INTO customers VALUES (6,00160);
INSERT INTO customers VALUES (7,00170);
INSERT INTO customers VALUES (8,00180);
INSERT INTO customers VALUES (9,00190);
INSERT INTO customers VALUES (10,00200);

INSERT INTO customers VALUES (11,00201);
INSERT INTO customers VALUES (12,00202);

CREATE TABLE company(
    IIN varchar(30) PRIMARY KEY,
    budget int NOT NULL,
    FOREIGN KEY (IIN) REFERENCES customers(IIN)
);
INSERT INTO company VALUES (11,100000);
INSERT INTO company VALUES (12,150000);

CREATE TABLE person(
    IIN varchar(30) PRIMARY KEY,
    surname varchar(30) NOT NULL,
    name varchar(30) NOT NULL,
    m_name varchar(30) NOT NULL,
    gender varchar(3) NOT NULL,
    annual_income int NOT NULL,
    FOREIGN KEY (IIN) REFERENCES customers(IIN)
);
INSERT INTO person VALUES (1,'Elnur','Dias','N.','M',110);
INSERT INTO person VALUES (2,'Temirlan','Madiev','J.','M',520);
INSERT INTO person VALUES (3,'Nurbol','Serik','L.','M',880);
INSERT INTO person VALUES (4,'Anuar','Kadyr','H.','M',690);
INSERT INTO person VALUES (5,'Dinara','Sarsenova','Q.','F',770);
INSERT INTO person VALUES (6,'Asem','Bakyt','I.','F',1000);
INSERT INTO person VALUES (7,'Aigul','Seit','P.','F',998);
INSERT INTO person VALUES (8,'Asyl','Zhigit','E.','M',451);
INSERT INTO person VALUES (9,'Sasha','Egorova','T.','F',150);
INSERT INTO person VALUES (10,'Aidana','Anar','V.','F',820);


CREATE TABLE phone_number(
    customer_IIN varchar(30),
    phone_number varchar NOT NULL,
    PRIMARY KEY (customer_IIN,phone_number),
    FOREIGN KEY (customer_IIN) REFERENCES customers(IIN)
);
INSERT INTO phone_number VALUES (1,87479831627);
INSERT INTO phone_number VALUES (2,87479831623);
INSERT INTO phone_number VALUES (3,87479831342);
INSERT INTO phone_number VALUES (4,87479833627);
INSERT INTO phone_number VALUES (5,87479253627);
INSERT INTO phone_number VALUES (6,87379831627);
INSERT INTO phone_number VALUES (7,87479131627);
INSERT INTO phone_number VALUES (8,87479801627);
INSERT INTO phone_number VALUES (9,87403831627);
INSERT INTO phone_number VALUES (10,87009831627);
INSERT INTO phone_number VALUES (10,87000831627);
INSERT INTO phone_number VALUES (10,87100811117);

CREATE TABLE orders(
    ORD_IN varchar(30) PRIMARY KEY,
    oper_type varchar(10) NOT NULL,
    amount int NOT NULL,
    date date DEFAULT now(),
    DEAL_IN varchar(30) NOT NULL,
    CUST_IN varchar(30) NOT NULL,
    VIN varchar(30) NOT NULL UNIQUE,
    FOREIGN KEY (DEAL_IN) REFERENCES dealers(DEAL_IN),
    FOREIGN KEY (CUST_IN) REFERENCES customers(IIN),
    FOREIGN KEY (VIN) REFERENCES vehicle(VIN)
);
INSERT INTO orders VALUES(1,'Purchase',10000,'2020-02-01',1,1,1);
INSERT INTO orders VALUES(2,'Purchase',12000,'2020-02-01',2,2,2);
INSERT INTO orders VALUES(3,'Purchase',5010,'2020-03-15',1,3,3);
INSERT INTO orders VALUES(4,'Purchase',7000,'2019-10-03',3,4,4);
INSERT INTO orders VALUES(5,'Purchase',6050,'2019-07-23',2,5,5);
INSERT INTO orders VALUES(6,'Purchase',13004,'2019-08-20',3,6,6);
INSERT INTO orders VALUES(7,'Purchase',9900,'2021-12-12',1,7,7);
INSERT INTO orders VALUES(8,'Purchase',1111,'2021-09-12',3,8,8);
INSERT INTO orders VALUES(9,'Purchase',7992,'2021-05-09',2,9,9);
INSERT INTO orders VALUES(10,'Purchase',20000,'2010-04-30',3,10,10);

INSERT INTO orders VALUES(13,'Purchase',9092,'2021-05-09',2,1,13);
INSERT INTO orders VALUES(14,'Purchase',21000,'2010-04-30',3,2,14);
INSERT INTO orders VALUES(15,'Purchase',70012,'2021-05-09',1,3,15);
INSERT INTO orders VALUES(16,'Purchase',2020,'2010-04-30',3,4,16);
INSERT INTO orders VALUES(17,'Purchase',1002,'2021-05-09',2,5,17);
INSERT INTO orders VALUES(18,'Purchase',2000,'2010-04-30',1,6,18);
INSERT INTO orders VALUES(19,'Purchase',9992,'2021-05-09',2,7,19);
INSERT INTO orders VALUES(20,'Purchase',29900,'2010-04-30',1,8,20);

INSERT INTO orders VALUES(11,'Purchase',100000,'2021-05-09',1,11,11);
INSERT INTO orders VALUES(12,'Purchase',500000,'2010-04-30',1,12,12);

