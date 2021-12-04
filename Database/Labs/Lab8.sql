--1
    CREATE OR REPLACE FUNCTION INC(num INTEGER)
        RETURNS INTEGER AS $$
        BEGIN
        RETURN num+1;
    END;$$
    LANGUAGE plpgsql;

    SELECT INC(290); --291
----------------------------------------------------------------
    CREATE OR REPLACE FUNCTION SUMMA(num1 INTEGER,num2 INTEGER)
        RETURNS INTEGER AS $$
        BEGIN
        RETURN num1+num2;
    END;$$
    LANGUAGE plpgsql;

    SELECT SUMMA(5,10);
-----------------------------------------------------------------
    CREATE OR REPLACE FUNCTION DIV2(num INTEGER)
        RETURNS BOOLEAN AS $$
        BEGIN
        RETURN num%2=0;
    END;$$
    LANGUAGE plpgsql;

    SELECT DIV2(4); --True
    SELECT DIV2(13); --False
-----------------------------------------------------------------
    CREATE OR REPLACE FUNCTION PASS(password VARCHAR)
        RETURNS BOOLEAN AS $$
        DECLARE
            size BOOLEAN = FALSE;
            num BOOLEAN = FALSE;
            sp_sym BOOLEAN = FALSE;
            up_case BOOLEAN = FALSE;
        BEGIN
        size = length(password) > 5;
        num = password ~ E'.*\\d.*';
        sp_sym = password ~ E'.*[!@#$%^&?].*';
        up_case = LOWER(password)!=password;
        RETURN (size and num and sp_sym and up_case);
    END;$$
    LANGUAGE plpgsql;

--Your password must be at leas 6 characters and contain at least one:
-- 1. Upper case letter
-- 2. Digital number
-- 3. Special symbol !@#$%^&?
SELECT PASS('Biznes1!');    --True
SELECT PASS('Bi!1')         -- False
----------------------------------------------------------------------------
CREATE OR REPLACE FUNCTION TWO_OUT(num NUMERIC,OUT num2 NUMERIC, OUT num3 NUMERIC)
        AS $$
        BEGIN
        num2 = num * num;
        num3 = num2 * num;
    END;$$
    LANGUAGE plpgsql;

SELECT * FROM TWO_OUT(2); --Square and Cube
------------------------------------------------------------------------------
--2

CREATE TABLE example(
    name VARCHAR PRIMARY KEY,
    code VARCHAR NOT NULL,
    DOB date NOT NULL,
    PRICE INT NOT NULL,
    DO_NOT_DELETE VARCHAR,
    AGE INT DEFAULT 0,
    TOTAL_VAL INT DEFAULT 0
);
SELECT * FROM example;
INSERT INTO example VALUES ('Nur','B','2002-02-15',1200,'Yes');
UPDATE example SET price = 5000 WHERE name='Nur';
DELETE FROM example WHERE name='Nur';

CREATE TABLE example_audit(
    operation         varchar   NOT NULL,
    stamp             timestamp NOT NULL,

    name VARCHAR,
    code VARCHAR,
    DOB date NOT NULL,
    PRICE INT NOT NULL,
    DO_NOT_DELETE VARCHAR,
    AGE INT DEFAULT 0,
    TOTAL_VAL INT DEFAULT 0
);
SELECT * FROM example_audit;
DELETE FROM example_audit WHERE operation='INSERT';

CREATE OR REPLACE FUNCTION process_example() RETURNS TRIGGER AS $$
    BEGIN
        IF(TG_OP = 'DELETE') THEN
            INSERT INTO example_audit VALUES ('DELETE',now(),OLD.*);
        end if;
        IF(TG_OP = 'INSERT') THEN
            INSERT INTO example_audit VALUES ('INSERT',now(),NEW.*);
        end if;
        IF(TG_OP = 'UPDATE') THEN
            INSERT INTO example_audit VALUES ('UPDATE',now(),NEW.*);
        end if;
    RETURN NULL;
    END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER exam_trig
    AFTER INSERT OR UPDATE OR DELETE ON example
    FOR EACH ROW EXECUTE FUNCTION process_example();
-------------------------------------------------------------------
--2b
CREATE TRIGGER age
    BEFORE INSERT on example
    EXECUTE FUNCTION get_age();

CREATE OR REPLACE FUNCTION get_age_percent() RETURNS TRIGGER
AS $CODE$
DECLARE
    compute_age INTEGER;
    new_price INTEGER;
BEGIN
    compute_age = EXTRACT(YEAR from age(NEW.DOB));
    new_price = NEW.price + (NEW.price * 12) / 100;
    NEW.age = compute_age;
    NEW.total_val = new_price;
    RETURN NEW;
END
$CODE$
LANGUAGE plpgsql;
------------------------------------------------------------
--2d
CREATE TRIGGER no_del
    BEFORE DELETE ON example_audit
    FOR EACH ROW EXECUTE FUNCTION fake_del();

CREATE OR REPLACE FUNCTION fake_del() RETURNS TRIGGER
AS $CODE$
    BEGIN
    RETURN NULL;
END
$CODE$
LANGUAGE plpgsql;
---------------------------------------------------------------
--2e
CREATE TRIGGER launch_d_e
    AFTER INSERT ON example
    EXECUTE PROCEDURE launch_func();

CREATE FUNCTION launch_func () RETURNS trigger AS '
DECLARE
    valid BOOLEAN;
    res RECORD;
BEGIN
    valid = pass(NEW.code);
    res = two_out(NEW.PRICE);
    RETURN NULL;
END; '
LANGUAGE  plpgsql;
----------------------------------------------------------------
--3
/*
 Procedure:
    Procedures are basic PL SQL blocks to perform a specific action.
    Procedures will not return the value
    It does not contain return clause in header section
 Functions:
    Functions are blocks used mainly to perform the computations.
    Functions must return the value. When you are writing functions make sure that you can write the return statement.
 */
-----------------------------------------------------------------
--4
CREATE TABLE task4(
    id INTEGER PRIMARY KEY,
    name varchar,
    date_of_birth date,
    age INTEGER,
    salary INTEGER,
    workexperience INTEGER,
    discount INTEGER
);
SELECT * FROM task4;
INSERT INTO task4 VALUES (1, 'Nur Zhetessov', '2002-02-15', 19, 0, 0, 0);
INSERT INTO task4 VALUES (2, 'Abai', '1845-08-10', 58, 100, 30 , 0);
INSERT INTO task4 VALUES (3, 'Bayurzhan', '2002-08-10', 18, 20, 4 , 0);
INSERT INTO task4 VALUES (4, 'Asel', '2000-04-12', 22, 10, 5 , 0);
DELETE FROM task4 WHERE id=2;

CREATE OR REPLACE PROCEDURE calculate_by_exper()
LANGUAGE plpgsql
as $$
    DECLARE
        q record;
        new_salary integer;
        new_disc integer;
    BEGIN
        FOR q IN SELECT * FROM task4
        LOOP
            new_salary = q.salary + (((q.salary*10)/100) * (q.workexperience/2)) ;
            new_disc = q.discount;

            new_disc = new_disc + 10 + (q.workexperience/5);

            UPDATE task4 SET salary = new_salary WHERE id=q.id;
            UPDATE task4 SET discount = new_disc WHERE id=q.id;
        END LOOP;
    END;
$$;

CALL calculate_by_exper();

CREATE OR REPLACE PROCEDURE calculate_by_exper2()
LANGUAGE plpgsql
as $$
    DECLARE
        q record;
        new_salary integer;
        new_disc integer;
    BEGIN
        FOR q IN SELECT * FROM task4
        LOOP
            new_salary = q.salary;
            new_disc = q.discount;

            IF EXTRACT(YEAR FROM AGE(q.date_of_birth)) >= 40 THEN
                new_salary = new_salary + ((new_salary*15)/100) ;
            end if;
            IF q.workexperience > 8 THEN
                new_salary = new_salary + ((new_salary*15)/100) ;
                new_disc = 20;
            end if;

            UPDATE task4 SET salary = new_salary WHERE id=q.id;
            UPDATE task4 SET discount = new_disc WHERE id=q.id;
        end loop;
    END;
$$;

CALL calculate_by_exper2();

--------------------------------------------------------------------
--5
CREATE TABLE cd_members(
    memid INTEGER PRIMARY KEY,
    name VARCHAR,
    recommendedby INTEGER
);
INSERT INTO cd_members VALUES (2,'A',1);
INSERT INTO cd_members VALUES (3,'B',1);
INSERT INTO cd_members VALUES (4,'C',1);
INSERT INTO cd_members VALUES (1,'D',0);
INSERT INTO cd_members VALUES (5,'E',0);
INSERT INTO cd_members VALUES (6,'F',0);
SELECT * FROM cd_members;

WITH RECURSIVE find_feedback(recommender, member) AS (
	SELECT recommendedby, memid
		FROM cd_members
	UNION ALL
	SELECT cd.recommendedby, ff.member
		FROM find_feedback ff
		INNER JOIN cd_members cd
			ON cd.memid = ff.recommender
)
--SELECT * from find_feedback;

SELECT ff.member member, ff.recommender, cd.name
	FROM find_feedback ff
	INNER JOIN cd_members cd
		ON ff.recommender = cd.memid
	WHERE ff.member = 2 OR ff.member = 3
ORDER BY ff.member ASC, ff.recommender DESC;

--------------------------------------------------------
--5
with recursive recommenders(recommender, member) as (
	select recommendedby, memid
		from cd_members
	union all
	select mems.recommendedby, recs.member
		from recommenders recs
		inner join cd_members mems
			on mems.memid = recs.recommender
)
select recs.member member, recs.recommender, mems.name
	from recommenders recs
	inner join cd_members mems
		on recs.recommender = mems.memid
	where recs.member = 22 or recs.member = 12
order by recs.member asc, recs.recommender desc
