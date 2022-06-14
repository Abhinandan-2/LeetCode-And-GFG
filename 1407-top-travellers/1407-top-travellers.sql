# Write your MySQL query statement below
select u_name as name , sum(
case 
    when join_table.dis is not null then join_table.dis
    else 0
end
) as travelled_distance
from 
( select users.id as u_id , users.name as u_name , rides.id as r_id , rides.user_id as r_usid , rides.distance as dis 
 from users
 left join rides on users.id = rides.user_id
) as join_table
group by u_id
order by sum(join_table.dis) desc, u_name asc