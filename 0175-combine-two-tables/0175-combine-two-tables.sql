# Write your MySQL query statement below
select firstname, lastname,
city, state from 
person as p  left join 
Address as ad 
on p.personid=ad.personid;
