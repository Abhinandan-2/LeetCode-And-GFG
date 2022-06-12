# # Write your MySQL query statement below
# select s.name
# from salesperson as s 
# where (s.sales_id not in (select sales_id from orders)) or or (s.sales_id = o.sales_id and o.com_id not in (select com_id from company where name = 'RED'))
select name
from salesperson
where sales_id not in (select sales_id from orders where com_id in (select com_id from company where name = 'RED'))