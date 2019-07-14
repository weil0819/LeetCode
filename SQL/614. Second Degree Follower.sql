/*

614. Second Degree Follower -- Medium
https://leetcode.com/problems/second-degree-follower/

In facebook, there is a follow table with two columns: followee, follower.

Please write a sql query to get the amount of each follower’s follower if he/she has one.

For example:

+-------------+------------+
| followee    | follower   |
+-------------+------------+
|     A       |     B      |
|     B       |     C      |
|     B       |     D      |
|     D       |     E      |
+-------------+------------+
should output:
+-------------+------------+
| follower    | num        |
+-------------+------------+
|     B       |  2         |
|     D       |  1         |
+-------------+------------+
Explaination:
Both B and D exist in the follower list, when as a followee, B's follower is C and D, and D's follower is E. A does not exist in follower list.
 

 

Note:
Followee would not follow himself/herself in all cases.
Please display the result in follower's alphabet order.

*/

# Write your MySQL query statement below

# METHOD-I: USING SUBQUERY
SELECT DISTINCT follower, num
FROM follow, (
    SELECT followee, COUNT(DISTINCT follower) AS num 
    FROM follow 
    GROUP BY followee 
) AS tmp 
WHERE follower=tmp.followee 
ORDER BY follower
;

# METHOD-II: USING INNER JOIN
SELECT F1.follower, COUNT(DISTINCT F2.follower) AS num 
FROM follow F1 
JOIN follow F2 ON F1.follower=F2.followee 
GROUP BY F1.follower 
ORDER BY F1.follower 
;



