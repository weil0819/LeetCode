/*
614. Second Degree Follower
https://www.leetfree.com/problems/second-degree-follower.html

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

# 
select F1.follower as follower, count(distinct F2.follower) as num  # avoid duplicated records by using distinct
from follow F1 
	join follow F2 on (F1.follower = F2.followee)  # 
order by F1.follower
;