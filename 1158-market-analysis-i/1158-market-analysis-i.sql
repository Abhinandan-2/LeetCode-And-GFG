# Write your MySQL query statement below
# select user_id , join_date , count(
# case 
#     when user_id is not null then user_id
#     else 0
# end
# )
# from users
# left join orders on user_id = buyer_id 
# where year(order_date) = '2019'
# group by user_id
select user_id as buyer_id , join_date , if(orders_in_2019 is null , 0 , orders_in_2019) as orders_in_2019
from users
left join (
select user_id as id , count(user_id) as orders_in_2019
from users
left join orders on user_id = buyer_id 
where year(order_date) = '2019'
group by user_id ) as drived on user_id = id
