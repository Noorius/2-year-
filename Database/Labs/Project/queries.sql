---------------------------------------------------------------------
--Show sales trends for various brands over the past 3 years by year
SELECT EXTRACT(YEAR FROM ord.date) as year, b.BIN,COUNT(DISTINCT ord.ORD_IN) as trend
FROM orders ord,vehicle v,models mod,brands b
WHERE ord.VIN=v.VIN AND
      v.MOD_IN = mod.MOD_IN AND
      b.BIN = mod.BIN AND
      ord.date >= now()-interval'3 year'
GROUP BY year,b.BIN
ORDER BY b.BIN ASC, year ASC;

---------------------------------------------------------------------
--Show sales trends for various brands over the past 3 years by month
SELECT EXTRACT(MONTH FROM ord.date) as year, b.BIN,COUNT(DISTINCT ord.ORD_IN) as trend
FROM orders ord,vehicle v,models mod,brands b
WHERE ord.VIN=v.VIN AND
      v.MOD_IN = mod.MOD_IN AND
      b.BIN = mod.BIN AND
      ord.date >= now()-interval'3 year'
GROUP BY year,b.BIN
ORDER BY b.BIN ASC, year ASC;

---------------------------------------------------------------------
--Show sales trends for various brands over the past 3 years by week.
SELECT EXTRACT(WEEK FROM ord.date) as year, b.BIN,COUNT(DISTINCT ord.ORD_IN) as trend
FROM orders ord,vehicle v,models mod,brands b
WHERE ord.VIN=v.VIN AND
      v.MOD_IN = mod.MOD_IN AND
      b.BIN = mod.BIN AND
      ord.date >= now()-interval'3 year'
GROUP BY year,b.BIN
ORDER BY b.BIN ASC, year ASC;

---------------------------------------------------------------------
--Then break these data out by gender of the buyer
SELECT b.BIN, per.gender, EXTRACT(YEAR FROM ord.date) as year, COUNT(DISTINCT ord.ORD_IN) as trend
FROM orders ord,vehicle v,models mod,brands b,person per
WHERE ord.VIN=v.VIN AND
      v.MOD_IN = mod.MOD_IN AND
      b.BIN = mod.BIN AND
      ord.CUST_IN = per.IIN AND
      ord.date >= now()-interval'3 year'
GROUP BY per.gender,b.BIN, year
ORDER BY b.BIN ASC, year ASC;

-------------------------------------------------------------------------
--and then by income range
WITH series AS (
                SELECT generate_series(100, 1000, 200) AS r_from -- min, max, year interval
), range AS (
                SELECT r_from, (r_from + 199) AS r_to FROM series -- 9 = interval (10 years) minus 1
)
SELECT b.BIN, r_from, r_to, COUNT(DISTINCT ord.ORD_IN) as trend
FROM orders ord,vehicle v,models mod,brands b,person per, range
WHERE ord.VIN=v.VIN AND
      v.MOD_IN = mod.MOD_IN AND
      b.BIN = mod.BIN AND
      ord.CUST_IN = per.IIN AND
      ord.date >= now()-interval'3 year' AND
      per.annual_income BETWEEN r_from AND r_to
GROUP BY b.BIN, r_from, r_to
ORDER BY b.BIN ASC, r_from ASC;

--CHEKING
/*
SELECT ord.ORD_IN, b.bin,per.annual_income
FROM orders ord,vehicle v,models mod,brands b,person per
WHERE ord.VIN=v.VIN AND
      v.MOD_IN = mod.MOD_IN AND
      b.BIN = mod.BIN AND
      ord.CUST_IN = per.IIN AND
      ord.date >= now()-interval'3 year';*/

----------------------------------------------------------------
--Find the VIN of each car containing such a transmission and the customer to which it was sold. Between two dates of transmission made
SELECT v.VIN,surname,name,m_name,p.PART_IN,p.manufactured_date
FROM vehicle v, options op,part p,orders ord,person per
WHERE v.VIN=op.VIN AND
      p.PART_IN=op.transmission AND
      p.supp_in='9' AND
      ord.VIN=v.VIN AND
      per.IIN=ord.CUST_IN AND
      p.manufactured_date > '2021-01-09' AND p.manufactured_date < '2021-01-21';

-------------------------------------------------------------------------------
--Find the top 2 brands by dollar-amount sold in the past year.
SELECT b.BIN,SUM(ord.amount)
FROM orders ord,vehicle v,models mod,brands b
WHERE ord.VIN=v.VIN AND
      v.MOD_IN = mod.MOD_IN AND
      b.BIN = mod.BIN AND
      ord.date > now()-interval'1 year'
GROUP BY b.BIN
ORDER BY sum(ord.amount) DESC
LIMIT 2;

---------------------------------------------------------------------------
--Find the top 2 brands by unit sales in the past year.
SELECT b.BIN,COUNT(ord.ORD_IN)
FROM orders ord,vehicle v,models mod,brands b
WHERE ord.VIN=v.VIN AND
      v.MOD_IN = mod.MOD_IN AND
      b.BIN = mod.BIN AND
      ord.date > now()-interval'1 year'
GROUP BY b.BIN
ORDER BY COUNT(ord.amount) DESC
LIMIT 2;

---------------------------------------------------------------------------
--In what month(s) do convertibles sell best?
SELECT EXTRACT(MONTH FROM ord.date), count(DISTINCT ord.ORD_IN)
FROM orders ord, vehicle v, convertible conv, models mod
WHERE ord.VIN = v.VIN AND
      v.MOD_IN = mod.MOD_IN AND
      mod.MOD_IN = conv.MOD_IN
GROUP BY EXTRACT(MONTH FROM ord.date)
ORDER BY count(DISTINCT ord.ORD_IN) DESC;

---------------------------------------------------------------------------------
--Find those dealers who keep a vehicle in inventory for the longest average time
SELECT d.DEAL_IN, current_date, AVG(current_date-i.start_date) as days
FROM dealers d, inventory i
WHERE d.DEAL_IN = i.DEAL_IN
GROUP BY d.DEAL_IN
ORDER BY days DESC;

---------------------------------------------------------------------------------
--CHECKING
/*SELECT d.DEAL_IN, i.start_date, current_date, current_date-i.start_date as days
FROM dealers d, inventory i
WHERE d.DEAL_IN = i.DEAL_IN
ORDER BY days DESC;*/