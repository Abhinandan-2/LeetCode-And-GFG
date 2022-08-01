# Write your MySQL query statement below
select if(id<(select count(*) from seat), if(mod(id,2)=0 , id-1,id+1),if(mod(id,2)=0,id-1,id)) as id ,student
from seat
order by id asc;