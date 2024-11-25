# Write your MySQL query statement below
select d.name as Department, e.name as Employee, e.salary
from employee as e join department as d
on e.departmentId=d.id
where salary in (select max(salary) from employee where departmentId=d.id) 