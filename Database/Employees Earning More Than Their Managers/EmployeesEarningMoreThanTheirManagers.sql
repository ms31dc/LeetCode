select Name as Employee from Employee where Id in (select emp.Id from Employee as emp, Employee as man where emp.Salary > man.Salary and emp.ManagerId = man.Id)
