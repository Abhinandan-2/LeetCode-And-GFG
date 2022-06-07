# Write your MySQL query statement below
select employee_id, if((mod(employee_id,2)=1 and substr(name,1,1)!= 'M') ,salary , 0 ) as bonus
# case
#     when mod(salary,2) =1 and substr(name,1) != 'M' then salary 
#     else 0 
# end
from employees