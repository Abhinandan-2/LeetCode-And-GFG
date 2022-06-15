# Write your MySQL query statement below
select distinct(email) 
from person
left join
(
select email as emal , count(email) as number
from person
group by email
) as dup on email = emal
where number>1