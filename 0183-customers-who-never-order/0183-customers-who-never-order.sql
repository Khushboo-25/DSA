# Write your MySQL query statement below
select name as Customers from customers as cs where cs.id not in (select distinct customerid from orders);
