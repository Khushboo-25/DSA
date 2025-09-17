# Write your MySQL query statement below

select contest_id,round((count(user_id)/(select count(user_id) as tt from users))*100,2) as percentage from register group by contest_id
order by percentage desc,contest_id asc
-- join
-- (select count(user_id) as tt from users)