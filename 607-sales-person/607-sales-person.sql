select s.name
from salesperson s
left join orders o on (o.sales_id = s.sales_id)
left join company c on (o.com_id = c.com_id)
group by s.name
having count(order_id)=0 or not sum(c.name = 'RED')>0