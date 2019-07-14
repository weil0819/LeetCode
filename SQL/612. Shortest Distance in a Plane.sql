/*

612. Shortest Distance in a Plane -- Medium
https://leetcode.com/problems/shortest-distance-in-a-plane/

Table point_2d holds the coordinates (x,y) of some unique points (more than two) in a plane.
 

Write a query to find the shortest distance between these points rounded to 2 decimals.
 

| x  | y  |
|----|----|
| -1 | -1 |
| 0  | 0  |
| -1 | -2 |
 

The shortest distance is 1.00 from point (-1,-1) to (-1,2). So the output should be:
 

| shortest |
|----------|
| 1.00     |
 

Note: The longest distance among all the points are less than 10000.

*/

# Write your MySQL query statement below
# https://www.w3schools.com/sql/func_mysql_sqrt.asp
# https://www.w3schools.com/sql/func_mysql_pow.asp
SELECT ROUND(SQRT(MIN(POW(P1.x-P2.x,2)+POW(P1.y-P2.y,2))),2) AS shortest 
FROM point_2d P1, point_2d P2 
WHERE P1.x!=P2.x OR P1.y!=P2.y
;


