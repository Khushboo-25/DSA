# Write your MySQL query statement below
select e.name,b.bonus from employee as e left join bonus as b on
e.empId=b.empId where b.bonus<1000 or b.bonus is NULL; 