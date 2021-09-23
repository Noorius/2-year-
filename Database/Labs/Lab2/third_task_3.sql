CREATE table education_process(
    ep_id int PRIMARY KEY,
    ep_student INT REFERENCES student(st_id),
    ep_teacher INT REFERENCES teacher(t_id),
    ep_subject INT NOT NULL REFERENCES subject(sub_code),
    ep_room INT NOT NULL
);

CREATE table student(
    st_id INT PRIMARY KEY,
    st_name varchar(40) NOT NULL,
    st_surname varchar(40) NOT NULL,
    st_familyName varchar(40) NOT NULL ,
    UNIQUE(st_id,st_name,st_surname,st_familyName)
);

CREATE table teacher(
    t_id INT PRIMARY KEY,
    t_name varchar(40) NOT NULL ,
    t_surname varchar(40) NOT NULL ,
    t_familyName varchar(40) NOT NULL ,
    UNIQUE(t_id,t_name,t_surname,t_familyName)
);

CREATE table subject(
    sub_code INT PRIMARY KEY,
    sub_name varchar UNIQUE NOT NULL
);

INSERT INTO subject VALUES (1,'ADS');
INSERT INTO subject VALUES (2,'Databases');
INSERT INTO teacher VALUES (1,'Aibek','Kuralbaev','Middle Name');
INSERT INTO teacher VALUES (2,'Akshabaev','Askar','Middle Name');
INSERT INTO student VALUES (1,'Zhetessov','Nur','Muratovich');
INSERT INTO student VALUES (2,'Dairov','Olzhas','Middle Name');

INSERT INTO education_process VALUES (1,1,1,2,100);
INSERT INTO education_process VALUES (2,1,2,2,101);
INSERT INTO education_process VALUES (3,2,1,1,200);
INSERT INTO education_process VALUES (4,1,1,2,200);

SELECT ep_id,t_surname,st_surname,sub_name,ep_room FROM education_process,subject,teacher,student
WHERE ep_student=student.st_id and ep_teacher=teacher.t_id and ep_subject=subject.sub_code;



