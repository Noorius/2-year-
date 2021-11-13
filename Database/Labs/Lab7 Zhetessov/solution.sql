--1. Task
--Large objects (photos, videos, CAD files, etc.) are stored as a large object:
------• blob: binary large object -- object is a large collection of
--------uninterpreted binary data (whose interpretation is left to
--------an application outside of the database system)
--------
------• clob: character large object -- object is a large collection of character data

--- When a query returns a large object, a pointer is returned rather than the large object itself.
---Large objects may be stored either as files in a file system area managed by the
---database, or as file structures stored in and managed by the database. In the latter case,
---such in-database large objects can optionally be represented using B+-tree file organizations

--2. Task
--A role, a collection of privileges, is created by users . It simplifies privilege management by allowing to manage bundles of privileges.
--A privilege is a right to execute a particular type of SQL statement.
--A user is someone who can connect to a database and optionally can own objects in the database.

CREATE ROLE support;
CREATE ROLE accountant;
CREATE ROLE administrator;

--SELECT,INSERT,UPDATE, DELETE
GRANT SELECT,INSERT,UPDATE (status), DELETE ON transactions TO accountant;
GRANT SELECT on customers TO support;
GRANT SELECT, UPDATE(currency,"limit") on accounts TO support;
GRANT ALL PRIVILEGES on customers,accounts TO administrator;

CREATE USER Sultan;
CREATE USER Gaukhar WITH PASSWORD 'gaukhar123';
CREATE USER Alibek WITH PASSWORD 'alibek2000' VALID UNTIL '2022-01-01';

GRANT support TO sultan;
GRANT accountant TO gaukhar;
GRANT administrator TO alibek;

ALTER ROLE administrator CREATEROLE;
ALTER ROLE support CREATEROLE;

REVOKE DELETE on transactions FROM accountant;

REVOKE ALL PRIVILEGES ON transactions FROM accountant;
REVOKE ALL PRIVILEGES ON customers,accounts FROM support;
REVOKE ALL PRIVILEGES ON customers,accounts FROM administrator;
DROP ROLE accountant;
DROP ROLE administrator;
DROP ROLE support;

--3. Task
INSERT INTO transactions VALUES (4, '2021-06-05 18:02:55.000000', 'RS88012', 'NK90123', 10, 'init');
DELETE FROM transactions WHERE id=4;
SELECT * FROM transactions;

CREATE OR REPLACE PROCEDURE same_currencies(in id_name int)

language plpgsql
AS
$$
    DECLARE
        sr_curr varchar(3);
        ds_curr varchar(3);
    BEGIN
        SELECT currency INTO ds_curr FROM transactions t INNER JOIN accounts a on a.account_id = t.dst_account WHERE id=id_name;
        SELECT currency INTO sr_curr FROM transactions t INNER JOIN accounts a on a.account_id = t.src_account WHERE id=id_name;

        IF(ds_curr IS NULL or sr_curr IS NULL) THEN
            RAISE NOTICE 'Transaction is not valid';
            RETURN;
        END IF;

        ASSERT ds_curr=sr_curr, 'Unfortunately currencies are different in transactions';

    RAISE NOTICE 'Currencies are the same';
END$$;

CALL same_currencies(1); --It is OK
CALL same_currencies(3); --Does not exist
CALL same_currencies(4); --Currencies are different

--------------------------------------
ALTER TABLE customers
    ALTER COLUMN name SET NOT NULL,
    ALTER COLUMN birth_date SET NOT NULL;

ALTER TABLE accounts
    ALTER COLUMN customer_id SET NOT NULL,
    ALTER COLUMN currency SET NOT NULL,
    ALTER COLUMN balance SET DEFAULT 0,
    ALTER COLUMN balance SET NOT NULL;

ALTER TABLE transactions
    ALTER COLUMN date SET NOT NULL,
    ALTER COLUMN src_account SET NOT NULL,
    ALTER COLUMN dst_account SET NOT NULL,
    ALTER COLUMN amount SET NOT NULL,
    ALTER COLUMN status SET NOT NULL;

--4. Task
CREATE DOMAIN Cash AS varchar(3);

ALTER TABLE accounts
ALTER COLUMN currency TYPE Cash
USING accounts.currency::Cash;
--OR
SELECT *, CAST(currency AS Cash)
FROM accounts;

DROP TYPE Cash;

--5. Task
SELECT * FROM accounts;

INSERT INTO accounts VALUES ('CS88012', 203, 'KZT', 10000, -200); --Without Index

DELETE FROM accounts WHERE account_id='CS88012';

CREATE UNIQUE INDEX one_cust_one_curr ON accounts(customer_id,currency);

INSERT INTO accounts VALUES ('CS88012', 203, 'KZT', 10000, -200); --203 already has KZT currency account, Error

DROP INDEX one_cust_one_curr;

--5(2)
CREATE INDEX search_by_curr_bal on accounts(currency,balance);
CREATE INDEX search_trans1 on transactions(src_account);
CREATE INDEX search_trans2 on transactions(dst_account);
DROP INDEX search_by_curr_bal;
DROP INDEX search_trans1;
DROP INDEX search_trans2;

--OR

CREATE MATERIALIZED VIEW trans_account
    AS SELECT * FROM transactions,accounts
            WHERE src_account=accounts.account_id OR dst_account=accounts.account_id;

CREATE INDEX trans_acc ON trans_account(currency,balance);

DROP INDEX trans_acc;

--6. Task
UPDATE accounts SET balance = 600  WHERE account_id='RS88012';
DELETE FROM transactions WHERE id=3;
DELETE FROM transactions WHERE id=4;

CALL update_test(3,'RS88012', 'NT10204', 400);
CALL update_test(4,'RS88012', 'NT10204', 400);

SELECT * from transactions;
SELECT * from accounts;

--FIRST SOLUTION WITHOUT TABLE CHANGING

CREATE OR REPLACE PROCEDURE update_test(id_name int, sr varchar(40), ds varchar(40), cash_am int)
AS $$
DECLARE
    lim float;
    bal float;

BEGIN

    INSERT INTO transactions VALUES (id_name, now(), sr, ds, cash_am, 'init');

        UPDATE accounts SET balance = balance - cash_am
                WHERE account_id = sr;
        UPDATE accounts SET balance = balance + cash_am
                WHERE account_id = ds;

        SELECT balance INTO bal FROM accounts WHERE account_id=sr;
        SELECT "limit" INTO lim FROM accounts WHERE account_id=sr;

        if lim>bal then
            ROLLBACK;
            INSERT INTO transactions VALUES (id_name, now(), sr, ds, cash_am, 'rollback');
        else
            UPDATE transactions SET status='commited' WHERE id=id_name;
        end if;

END;
$$ LANGUAGE plpgsql;


--SECOND SOLUTION WITH TABLE CHANGING

ALTER TABLE accounts
ADD CONSTRAINT check_bal CHECK ( balance > "limit");

ALTER TABLE accounts
DROP CONSTRAINT check_bal;


CREATE OR REPLACE PROCEDURE update_test(id_name int, sr varchar(40), ds varchar(40), cash_am int)
AS $$
BEGIN
    INSERT INTO transactions VALUES (id_name, now(), sr, ds, cash_am, 'init');
    BEGIN
        UPDATE accounts SET balance = balance - cash_am
                WHERE account_id = sr;
        UPDATE accounts SET balance = balance + cash_am
                WHERE account_id = ds;
        EXCEPTION
            WHEN OTHERS THEN
                UPDATE transactions SET status='rollback' WHERE id=id_name;
                RETURN;

    END;
    UPDATE transactions SET status='commited' WHERE id=id_name;
END;
$$ LANGUAGE plpgsql;

/* DECLARE
        sr_curr varchar(3);
        ds_curr varchar(3);
        i int;
    BEGIN
        FOR i IN SELECT id FROM transactions LOOP
            SELECT currency INTO ds_curr FROM transactions t INNER JOIN accounts a on a.account_id = t.dst_account WHERE id=i;
            SELECT currency INTO sr_curr FROM transactions t INNER JOIN accounts a on a.account_id = t.src_account WHERE id=i;
            ASSERT ds_curr=sr_curr, 'Unfortunately currencies are different in transactions';
        end loop;
        Zhetessov Nur M.
*/







