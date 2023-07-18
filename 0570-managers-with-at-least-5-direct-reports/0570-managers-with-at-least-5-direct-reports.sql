# Write your MySQL query statement below
select name from employee e,
(select managerId from employee group by managerId having count(*)>=5) as m
where e.id=m.managerId
