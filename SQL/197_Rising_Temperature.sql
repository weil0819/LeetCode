/*
197. Rising Temperature
https://leetcode.com/problems/rising-temperature/description/

Given a Weather table, write a SQL query to find all dates' Ids with higher temperature compared to its previous (yesterday's) dates.

+---------+------------------+------------------+
| Id(INT) | RecordDate(DATE) | Temperature(INT) |
+---------+------------------+------------------+
|       1 |       2015-01-01 |               10 |
|       2 |       2015-01-02 |               25 |
|       3 |       2015-01-03 |               20 |
|       4 |       2015-01-04 |               30 |
+---------+------------------+------------------+

For example, return the following Ids for the above Weather table:

+----+
| Id |
+----+
|  2 |
|  4 |
+----+

*/

select W1.Id as Id 
from Weather W1, Weather W2 
where datediff(W1.RecordDate, W2.RecordDate) = 1 and W1.Temperature > W2.Temperature
;
