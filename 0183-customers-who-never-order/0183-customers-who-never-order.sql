SELECT a.name AS 'Customers'
FROM customers AS a
WHERE a.id NOT IN (SELECT b.customerid FROM orders AS b)
