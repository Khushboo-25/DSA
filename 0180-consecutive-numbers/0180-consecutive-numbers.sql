# Write your MySQL query statement below
select  distinct l1.num as ConsecutiveNums from
logs as l1 join logs as l2 join logs as l3 where 
(l1.num=l2.num  and l1.id=l2.id+1) and (l1.num=l3.num and l1.id=l3.id+2);