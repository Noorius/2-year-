--1. Initial phase - characterize fully the data needs of the prospective database users.
--2. Second phase - choosing a data model:
-- •    Applying the concepts of the chosen data model
-- •    Translating these requirements into a conceptual schema of the database.
-- •    A fully developed conceptual schema indicates the functional requirements.
--3. Final Phase - implementation of the database
-- • Logical Design – Deciding on the database schema.
-- • Physical Design – Deciding on the physical layout of the database

--Entity Relationship Model (ER Model)
--  Model of an enterprise as a collection of:
--      • entities (distinguishable “thing” or “object”)
--      • relationships (an association among several entities)
--  ...represented diagrammatically by an ER diagram.

-------------------------------------------------------------------------------------
--1
create table student_lab4
	(ID	            varchar(9) PRIMARY KEY, --simple
	 first_name     varchar not null, --simple
	 last_name      varchar not null,
	 middle_name    varchar not null,
	 full_name varchar GENERATED ALWAYS AS(last_name||' '||first_name||' '||middle_name) STORED, --composite
	 DOB            date,
	 age int GENERATED ALWAYS AS(get_age(DOB)) STORED, --derived
	 UNIQUE(full_name)
	);

create table phone
    (ID             varchar(9) REFERENCES student_lab4(ID),
    phone_number    varchar(11), --multivalued
    primary key(ID)
);

CREATE OR REPLACE FUNCTION get_age( birthday date )
RETURNS int
AS $CODE$
BEGIN
    RETURN EXTRACT(YEAR from age(birthday));
END
$CODE$
LANGUAGE plpgsql IMMUTABLE;

INSERT INTO student_lab4(ID, first_name, last_name, middle_name, DOB) VALUES('0','Nur','Zhetessov','Muratovich','2002-02-15');
INSERT INTO student_lab4(ID, first_name, last_name, middle_name, DOB) VALUES('1','Aibol','Rakhimov','Sultanovich','2002-03-25');
INSERT INTO student_lab4(ID, first_name, last_name, middle_name, DOB) VALUES('3','Kenesary','Kasymov','Khan','2000-01-01');


SELECT * from student_lab4;

-----------------------------------------------------------------
--2
create table faculty
	(faculty_id smallserial PRIMARY KEY,
	 faculty_name   varchar(20) NOT NULL,
	 year int NOT NULL,
	 budget         numeric(12,2) check (budget > 0) DEFAULT 0
	);
INSERT INTO faculty(faculty_name, year, budget) VALUES ('FIT',2021,10101010.00);

create table university(
    univ_id smallserial PRIMARY KEY,
    univ_full_name varchar NOT NULL,
    un_street varchar NOT NULL,
    un_building_num varchar NOT NULL
);

create table course_lab4
	(course_id          varchar(8) PRIMARY KEY,
	 title              varchar(50) NOT NULL,
	 credits		    numeric(2,0) check (credits > 0) NOT NULL
	);
INSERT INTO course_lab4 VALUES ('0','Databases',3);

create table teacher_lab4
	(ID	varchar(9),
	 t_name varchar(20) NOT NULL,
	 t_surname varchar(20) NOT NULL,
	 t_midname varchar(20) NOT NULL,
	 t_full_name varchar(61) GENERATED ALWAYS AS(t_name||' '||t_surname||' '||t_midname) STORED,
	 salary	numeric(8,2) check (salary >= 14500) DEFAULT 14500,
	 primary key (ID)
	);
INSERT INTO teacher_lab4 VALUES ('0','Aibek','Kuralbaev','T.',DEFAULT,500000.00);

create table room
    (
        room_num varchar(4) PRIMARY KEY,
        total_size smallserial
    );
INSERT INTO room VALUES ('100A');
INSERT INTO room VALUES ('101A');
INSERT INTO room VALUES ('102A');

--CREATE student_lab4 table please

create table classrooms
    (cl_number varchar(5) PRIMARY KEY,
     building_side varchar CHECK ( building_side in('Tole','Panfilov','Ablay','Aiteke') )
    );

create table office_reg
    (l_id smallserial UNIQUE,
     day			varchar(3) CHECK(day in ('Mon','Tue','Wed','Thu','Fri','Sat','Sun')) ,
	 start_hr		numeric(2) check (start_hr >= 0 and start_hr < 21),
	 start_min		numeric(2) check (start_min >= 0 and start_min < 60),
	 end_hr			numeric(2) check (end_hr >= 9 and end_hr <= 22),
	 end_min		numeric(2) check (end_min >= 0 and end_min < 60),
	 primary key (l_id, day, start_hr, start_min)
    );

create table supports(
    un_id int REFERENCES university(univ_id) NOT NULL,
    faculty_id int REFERENCES faculty(faculty_id) NOT NULL,
    PRIMARY KEY (un_id,faculty_id)
);

create table studies(
    st_id varchar REFERENCES student_lab4(ID) NOT NULL,
    faculty_id int REFERENCES faculty(faculty_id) NOT NULL,
    PRIMARY KEY (st_id,faculty_id)
);

create table teaches(
    lesson_id int REFERENCES office_reg(l_id) NOT NULL,
    t_id varchar REFERENCES teacher_lab4(ID) NOT NULL,
    PRIMARY KEY (lesson_id,t_id)
);

create table schedules(
    course_id varchar REFERENCES course_lab4(course_id) NOT NULL,
    lesson_id int REFERENCES office_reg(l_id) NOT NULL,
    PRIMARY KEY (course_id,lesson_id)
);

create table dorm_student
    (room_num varchar(4) REFERENCES room(room_num) NOT NULL,
     student_name varchar(61) REFERENCES student_lab4(full_name),
     num_of_students smallserial CHECK (num_of_students<=2),
     PRIMARY KEY (room_num)
    );
INSERT INTO dorm_student(room_num, student_name) VALUES ('100A','Zhetessov Nur Muratovich');
INSERT INTO dorm_student(room_num, student_name) VALUES ('100A','Rakhimov Aibol Sultanovich');
INSERT INTO dorm_student(room_num, student_name) VALUES ('100A','Kasymov Kenesary Khan');

create table works
    (faculty_id int REFERENCES faculty(faculty_id) NOT NULL,
     t_id varchar(9) REFERENCES teacher_lab4(ID) NOT NULL,
     start_year int NOT NULL,
     PRIMARY KEY (faculty_id,t_id)
    );

create table takes_place(
    l_id smallint REFERENCES office_reg(l_id) NOT NULL,
    cl_number varchar(5) REFERENCES classrooms(cl_number) NOT NULL,
    PRIMARY KEY (l_id,cl_number)
);

create table learns
    (l_id int REFERENCES office_reg(l_id) NOT NULL,
     s_id varchar REFERENCES student_lab4(ID) NOT NULL,
     point numeric(2,1),
     attendance boolean DEFAULT FALSE,
     PRIMARY KEY (l_id,s_id)
    );

--Осуществляет контроль над регистрацией на дисциплины семестра и за формированием расписания учебных занятий обучающихся.
--Осуществляет контроль над подписанием индивидуальных учебных планов обучающихся. Готовит информацию о личных и академических данных студентов в Университете.
-- Осуществляет контроль за подсчетом оценки. Контролирует регистрационную базу данных «Студенты». Оказывает сотрудникам университета методическую и практическую помощь по работе с информационным корпоративным порталом UNINET, сотрудничает с Департаментом IT КБТУ по вопросам совершенствования автоматизированной системы «Офис Регистратора».
-- Ведет сбор экзаменационных ведомостей по результатам сессий.
-- Ведет учет движения контингента    студентов по формам и отделениям. представляет соответствующую справочную информацию о контингенте обучающихся. Организует летний семестр для ликвидации академической задолженности или разницы в учебных планах.
--Осуществляет прием, хранение и ведение личных дел студентов.


DROP TABLE phone;
DROP TABLE teaches;
DROP TABLE dorm_student;
DROP TABLE learns;
DROP TABLE schedules;
DROP TABLE studies;
DROP TABLE supports;
DROP TABLE takes_place;
DROP TABLE works;
DROP TABLE office_reg;
DROP TABLE course_lab4;
DROP TABLE teacher_lab4;
DROP TABLE student_lab4;
DROP TABLE classrooms;
DROP TABLE room;
DROP table university;
DROP TABLE faculty;