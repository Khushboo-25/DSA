# Write your MySQL query statement belo
select project_id,round(avg(experience_years),2) as average_years from (select project_id,employee_id from project  ) as p1 left join (select employee_id,experience_years from employee) as p2
on p1.employee_id= p2.employee_id group by project_id; 
