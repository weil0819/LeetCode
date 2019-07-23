/*

571. Find Median Given Frequency of Numbers -- Hard
https://leetcode.com/problems/find-median-given-frequency-of-numbers/


The Numbers table keeps the value of number and its frequency.

+----------+-------------+
|  Number  |  Frequency  |
+----------+-------------|
|  0       |  7          |
|  1       |  1          |
|  2       |  3          |
|  3       |  1          |
+----------+-------------+
In this table, the numbers are 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 3, so the median is (0 + 0) / 2 = 0.

+--------+
| median |
+--------|
| 0.0000 |
+--------+
Write a query to find the median of all numbers and name the result as median.

*/

# Write your MySQL query statement below

# METHOD-I: compute sum of larger and smaller numbers, difference should be less than frequency
SELECT AVG(N.Number) AS median 
FROM Numbers N
WHERE ABS((SELECT SUM(Frequency) FROM Numbers N1 WHERE N.Number<=N1.Number)
          -(SELECT SUM(Frequency) FROM Numbers N2 WHERE N.Number>=N2.Number))<=N.Frequency 
;


