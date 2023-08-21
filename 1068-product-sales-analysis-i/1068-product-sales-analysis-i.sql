# Write your MySQL query statement below
# select product_name from product, year, price from product, sales
select product_name, year, price from sales
join product
on sales.product_id=product.product_id
