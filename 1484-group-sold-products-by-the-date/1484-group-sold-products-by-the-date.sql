# Write your MySQL query statement below

# select a.sell_date, count(distinct a.product) as num_sold from activities a, 
# (select product as products) from activities b 
# group by sell_date
# having b.sell_date=a.sell_date

SELECT a.sell_date,
       COUNT(DISTINCT a.product) AS num_sold,
       GROUP_CONCAT(DISTINCT a.product) AS products
FROM activities a
GROUP BY a.sell_date;
