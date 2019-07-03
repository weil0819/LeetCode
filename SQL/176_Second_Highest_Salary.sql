/*
176. Second Highest Salary
https://leetcode.com/problems/second-highest-salary/description/

Write a SQL query to get the second highest salary from the Employee table.

+----+--------+
| Id | Salary |
+----+--------+
| 1  | 100    |
| 2  | 200    |
| 3  | 300    |
+----+--------+

For example, given the above Employee table, the query should return 200 as the second highest salary. If there is no second highest salary, then the query should return null.

+---------------------+
| SecondHighestSalary |
+---------------------+
| 200                 |
+---------------------+

*/

# method-I:
select max(Salary) as SecondHighestSalary 
            from Employee 
            where Salary < (select max(Salary) from Employee);

# method-II:
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary
;

# method-III:
# Using IFNULL and LIMIT clause
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) 						# if query return null, should return NULL as SecondHighestSalary
    AS SecondHighestSalary;


