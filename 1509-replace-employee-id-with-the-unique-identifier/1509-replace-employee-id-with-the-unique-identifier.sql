# Write your MySQL query statement below

select  eu.unique_id as unique_id, e.name from employees as e left join employeeuni as eu on
e.id=eu.id;