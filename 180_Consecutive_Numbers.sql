/*
180. Consecutive Numbers

Write a SQL query to find all numbers that appear at least three times consecutively.

+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+
For example, given the above Logs table, 1 is the only number that appears consecutively for at least three times.

+-----------------+
| ConsecutiveNums |
+-----------------+
| 1               |
+-----------------+

*/

# Write your MySQL query statement below
SELECT DISTINCT L1.Num AS ConsecutiveNums    # use DISTINCT to avoid consecutively appearing more than 3 times
FROM Logs L1
    JOIN Logs L2 on (L1.Num = L2.Num)     # utlize three same tables to analyze their relationships
    JOIN Logs L3 on (L2.Num = L3.Num)
WHERE L2.Id-L1.Id=1 AND L3.Id-L2.Id=1;
