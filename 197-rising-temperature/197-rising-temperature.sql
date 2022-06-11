# Write your MySQL query statement below
select distinct id
from weather as w
where date_sub(w.recorddate,interval 1 day) in (select recorddate from weather as a where w.temperature>a.temperature)