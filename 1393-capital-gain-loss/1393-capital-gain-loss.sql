# Write your MySQL query statement below
select sell_table.stock_name , sell_table.total_price-buy_table.total_price as capital_gain_loss
from 
(select stock_name , sum(price) as total_price
from stocks
where operation = 'Sell'
group by stock_name
) as sell_table ,
(select stock_name , sum(price) as total_price
from stocks
where operation = 'Buy'
group by stock_name
) as buy_table
where sell_table.stock_name = buy_table.stock_name

