# Write your MySQL query statement below
with new_table as
(
    select d.name as department,
    e.name as employee,
    e.salary as salary,
    rank() over(partition by d.id order by e.salary desc) as rnk
    from employee e
    join
    department d
    on e.departmentid=d.id
)
select department,employee,salary from new_table 
where rnk<=1;