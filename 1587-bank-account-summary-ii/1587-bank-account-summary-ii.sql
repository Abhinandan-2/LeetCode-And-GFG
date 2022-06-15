# Write your MySQL query statement below
select name , temp.balance
from users
left join
(select account as ac , sum(amount) as balance from Transactions group by account) as temp on account = ac
where temp.balance >10000