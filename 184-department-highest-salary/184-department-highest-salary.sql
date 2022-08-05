SELECT d1.Name as Department
    , e1.Name as Employee
    , e1.Salary
FROM (
    SELECT d.Id
        , MAX(d.Name) AS Name
        , MAX(e.Salary) AS Salary
    FROM Department d
    JOIN Employee e
    ON e.DepartmentId = d.Id
    GROUP BY d.Id
) d1
JOIN Employee e1
ON d1.Id = e1.DepartmentId AND e1.Salary = d1.Salary