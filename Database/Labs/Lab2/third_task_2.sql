CREATE table languages(
    instructor_id varchar(9) NOT NULL,
    first_name varchar(40) NOT NULL,
    last_name varchar(40) NOT NULL,
    middle_name varchar(40) NOT NULL,
    language varchar,
    FOREIGN KEY(instructor_id,first_name,last_name,middle_name) references instructors(id, first_name, last_name, middle_name)
);

CREATE table instructors(
    id varchar(9) PRIMARY KEY,
    first_name varchar(40) NOT NULL,
    last_name varchar(40) NOT NULL,
    middle_name varchar(40) NOT NULL,
    remote_lessons boolean NOT NULL,
    UNIQUE(id,first_name,last_name,middle_name)
);

CREATE table works(
    employee_id varchar(9),
    company_name varchar NOT NULL,
    duration smallint NOT NULL CHECK(duration>=0),
    additional_info text,
    FOREIGN KEY(employee_id) references instructors(id)
);

INSERT INTO languages VALUES ('20BD00001','Nur','Zhetessov','Muratovich','Russian');
INSERT INTO languages VALUES ('20BD00001','Nur','Zhetessov','Muratovich','Kazakh');
INSERT INTO instructors VALUES ('20BD00001','Nur','Zhetessov','Muratovich',TRUE);
INSERT INTO instructors VALUES ('20BD00002','Marat','Zhetessov','Boratovich',FALSE);

SELECT id,instructors.first_name,instructors.last_name,languages.language FROM instructors, languages WHERE instructors.id=languages.instructor_id;
SELECT * FROM languages;




