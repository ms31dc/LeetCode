select name as Customers from Customers where Id not in (select distinct(CustomerID) from orders)
