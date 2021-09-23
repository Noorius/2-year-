CREATE table  customers
(
    id integer not null,
    full_name varchar(50) not null,
    timestamp timestamp not null,
    delivery_address text not null,
    primary key(id),
    unique (id)
);

CREATE table orders
(
    code int NOT NULL,
    customer_id int,
    total_sum double precision NOT NULL CHECK(total_sum > 0),
    is_paid boolean NOT NULL,
    primary key(code),
    foreign key(customer_id) references customers(id)
);

CREATE table products(
    id varchar not null,
    name varchar not null,
    description text,
    price double precision not null check(price > 0),
    primary key(id),
    unique(id,name)
);

CREATE table order_items(
    order_code int NOT NULL,
    product_id varchar NOT NULL,
    quantity int NOT NULL CHECK(quantity > 0),
    primary key(order_code,product_id),
    foreign key(order_code) references orders(code),
    foreign key(product_id) references products(id)
);

--Exercise 4
INSERT INTO customers VALUES (1,'Zhetessov Nur','2020-12-01 00:00:10','Almaty');
INSERT INTO customers VALUES (2,'Nurtas Kairat','2045-12-01 00:00:10','Astana');
INSERT INTO customers VALUES (3,'Baiterek','3020-12-01 00:00:10','Astana');

SELECT * FROM customers;
UPDATE customers SET full_name='Nur' WHERE id=1;
UPDATE customers SET delivery_address='Nur-Sultan' WHERE delivery_address='Astana';
DELETE FROM customers WHERE delivery_address='Astana' and id=3;








