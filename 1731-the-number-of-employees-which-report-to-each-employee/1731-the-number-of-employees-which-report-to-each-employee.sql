# Write your MySQL query statement below
select mgr.employee_id,mgr.name,count(*) as reports_count,ROUND(AVG(e.age)) as average_age
from Employees e
join Employees mgr on e.reports_to=mgr.employee_id
group by mgr.employee_id,mgr.name
order by mgr.employee_id;