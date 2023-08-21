# # Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary as Salary from employee e,
(select max(salary) as mx, departmentId as id from employee group by departmentId) t,
department d
where e.departmentId=t.id
and e.departmentId=d.id
and e.salary=t.mx
