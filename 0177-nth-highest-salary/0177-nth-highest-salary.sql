CREATE FUNCTION getNthHighestSalary(n INT) RETURNS INT
BEGIN
set n=n-1;
 RETURN (
    select distinct salary from employee order by salary desc limit n,1
     # Write your MySQL query statement below.

  );
END