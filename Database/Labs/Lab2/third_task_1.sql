CREATE table students(
    id varchar(9) PRIMARY KEY,
    first_name varchar(40) NOT NULL,
    last_name varchar(40) NOT NULL,
    middle_name varchar(40) NOT NULL,
    gender bytea NOT NULL,
    birth_date date NOT NULL,

    UNIQUE(id,first_name,last_name,middle_name)
);

CREATE table students_info(
    id varchar(9) PRIMARY KEY,
    age smallint NOT NULL CHECK(age>0),
    info text,

    foreign key(id) references students(id)
);

CREATE table dormitory_need(
    id varchar(9) PRIMARY KEY,
    need boolean DEFAULT FALSE,
    foreign key(id) references students(id)
);

CREATE table grades(
    id varchar(9) PRIMARY KEY,
    av_grade numeric(3,2) NOT NULL,
    foreign key(id) references students(id)
);

INSERT INTO students VALUES('1','Nur','Zhetessov','Muratovich','М','2002-02-15');
INSERT INTO students VALUES('2','Marat','Zhetessov','Muratovich','М','2003-02-15');

INSERT INTO students_info VALUES('1',19);
INSERT INTO students_info VALUES('2',19);
INSERT INTO dormitory_need VALUES ('1',FALSE);
INSERT INTO dormitory_need VALUES ('2',TRUE);

SELECT students.id,first_name,last_name,middle_name,gender, birth_date, age,info,need
FROM students,students_info,dormitory_need
WHERE students.id=students_info.id and students.id=dormitory_need.id;

SELECT * FROM students,students_info,dormitory_need;

SELECT * FROM students;
SELECT * FROM students_info;
SELECT * FROM dormitory_need;

