# Write your MySQL query statement below
select customer_id, count(customer_id) as count_no_trans
from (select customer_id  from visits where visit_id not in (select visit_id from transactions)) as p
group by customer_id
order by customer_id