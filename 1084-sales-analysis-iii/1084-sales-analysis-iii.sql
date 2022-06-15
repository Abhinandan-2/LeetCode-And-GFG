# Write your MySQL query statement below
# select product_id as id, product_name
# from product
# left join sales on id = product_id
# where sale_date >= '2019-01-01' and sale_dae <= '2019-03-31'
# group by id
select product_id , product_name
from product
left join (
select product_id as id
from sales
group by product_id
having min(sale_date) >= '2019-01-01' and max(sale_date) <= '2019-03-31'
) as temp on product_id = id
where id is not null