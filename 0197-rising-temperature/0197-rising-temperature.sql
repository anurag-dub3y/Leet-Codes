# Write your MySQL query statement below
select w.id from weather w, weather x
where DATEDIFF(w.recordDate, x.recordDate) = 1 and w.temperature>x.temperature
