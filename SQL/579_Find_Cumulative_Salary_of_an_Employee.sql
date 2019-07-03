/*
579. Find Cumulative Salary of an Employee
https://www.leetfree.com/problems/find-cumulative-salary-of-an-employee.html

The Employee table holds the salary information in a year.

Write a SQL to get the cumulative sum of an employee's salary over a period of 3 months but exclude the most recent month.

The result should be displayed by 'Id' ascending, and then by 'Month' descending.

Example
Input

| Id | Month | Salary |
|----|-------|--------|
| 1  | 1     | 20     |
| 2  | 1     | 20     |
| 1  | 2     | 30     |
| 2  | 2     | 30     |
| 3  | 2     | 40     |
| 1  | 3     | 40     |
| 3  | 3     | 60     |
| 1  | 4     | 60     |
| 3  | 4     | 70     |

Output

| Id | Month | Salary |
|----|-------|--------|
| 1  | 3     | 90     |
| 1  | 2     | 50     |
| 1  | 1     | 20     |
| 2  | 1     | 20     |
| 3  | 3     | 100    |
| 3  | 2     | 40     |

Explanation
Employee '1' has 3 salary records for the following 3 months except the most recent month '4': salary 40 for month '3', 30 for month '2' and 20 for month '1'
So the cumulative sum of salary of this employee over 3 months is 90(40+30+20), 50(30+20) and 20 respectively.

| Id | Month | Salary |
|----|-------|--------|
| 1  | 3     | 90     |
| 1  | 2     | 50     |
| 1  | 1     | 20     |

Employee '2' only has one salary record (month '1') except its most recent month '2'.

| Id | Month | Salary |
|----|-------|--------|
| 2  | 1     | 20     |

Employ '3' has two salary records except its most recent pay month '4': month '3' with 60 and month '2' with 40. So the cumulative salary is as following.

| Id | Month | Salary |
|----|-------|--------|
| 3  | 3     | 100    |
| 3  | 2     | 40     |

*/

# return the cumulative sum for 3 months
select E1.id, E1.month, (E1.salary+E2.salary+E3.salry) as salary
from Employee E1, Employee E2, Employee E3 
where E1.month-1 = E2.month and E1.id = E2.id and E1.month-E3.month = 2 and E1.id = E3.id
order by E1.id asc, E1.month desc;

# return the most recent month for different id
select id, max(month) as month
from Employee 
group by id 
having count(*) > 1;

# return 
SELECT
    E1.id,
    E1.month,
    (E1.salary+E2.salary+E3.salry) AS Salary
FROM
    (SELECT
        id, MAX(month) AS month
    FROM
        Employee
    GROUP BY id
    HAVING COUNT(*) > 1) AS maxmonth
        JOIN
    Employee E1 ON (maxmonth.id = E1.id
        AND maxmonth.month > E1.month)
        JOIN
    Employee E2 ON (E2.id = E1.id
        AND E2.month = E1.month - 1)
        JOIN
    Employee E3 ON (E3.id = E1.id
        AND E3.month = E1.month - 2)
ORDER BY id ASC , month DESC
;