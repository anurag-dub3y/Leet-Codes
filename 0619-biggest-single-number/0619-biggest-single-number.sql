# Write your MySQL query statement below
# select num from MyNumbers group by num having count(*)=1 order by num desc limit 0,1;
SELECT COALESCE(
    (SELECT num
     FROM MyNumbers
     GROUP BY num
     HAVING COUNT(*) = 1
     ORDER BY num DESC
     LIMIT 1),
    NULL) AS num;

