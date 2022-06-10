# Write your MySQL query statement below
select max(salary) as secondhighestsalary
from employee
where salary  != (select max(salary) from employee)