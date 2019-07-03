/*
570. Managers with at Least 5 Direct Reports
https://www.leetfree.com/problems/managers-with-at-least-5-direct-reports.html

The Employee table holds all employees including their managers. Every employee has an Id, and there is also a column for the manager Id.

+------+----------+-----------+----------+
|Id    |Name 	  |Department |ManagerId |
+------+----------+-----------+----------+
|101   |John 	  |A 	      |null      |
|102   |Dan 	  |A 	      |101       |
|103   |James 	  |A 	      |101       |
|104   |Amy 	  |A 	      |101       |
|105   |Anne 	  |A 	      |101       |
|106   |Ron 	  |B 	      |101       |
+------+----------+-----------+----------+

Given the Employee table, write a SQL query that finds out managers with at least 5 direct report. For the above table, your SQL query should return:

+-------+
| Name  |
+-------+
| John  |
+-------+

Note:
No one would report to himself.

*/

SELECT E1.Name 
FROM Employee E1
WHERE E1.Id in (SELECT E2.ManagerId 
				FROM Employee E2 
				GROUP BY E2.ManagerId 
				HAVAING COUNT(*) >= 5)
;

SELECT e2.Name  
FROM Employee e1, Employee e2  
WHERE e1.ManagerId = e2.Id  
GROUP BY e1.ManagerId  
HAVAING COUNT(*) >= 5;  
