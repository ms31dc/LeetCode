CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (select ifnull((select distinct(Salary) from Employee order by Salary desc limit N,1), null)as getNthHighestSalary);
END
