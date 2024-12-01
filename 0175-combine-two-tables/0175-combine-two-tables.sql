# Write your MySQL query statement below

select p.firstName,p.lastName ,q.city,q.state from person as p left join address as q on p.personId=q.personId;