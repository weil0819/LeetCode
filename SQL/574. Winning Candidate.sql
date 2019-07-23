/*

574. Winning Candidate -- Medium
https://leetcode.com/problems/winning-candidate/

SQL Schema
Table: Candidate

+-----+---------+
| id  | Name    |
+-----+---------+
| 1   | A       |
| 2   | B       |
| 3   | C       |
| 4   | D       |
| 5   | E       |
+-----+---------+  
Table: Vote

+-----+--------------+
| id  | CandidateId  |
+-----+--------------+
| 1   |     2        |
| 2   |     4        |
| 3   |     3        |
| 4   |     2        |
| 5   |     5        |
+-----+--------------+
id is the auto-increment primary key,
CandidateId is the id appeared in Candidate table.
Write a sql to find the name of the winning candidate, the above example will return the winner B.

+------+
| Name |
+------+
| B    |
+------+
Notes:

You may assume there is no tie, in other words there will be at most one winning candidate.

*/

# Write your MySQL query statement below
# SELECT Name 
# FROM Candidate 
# WHERE id = (
#     SELECT CandidateId 
#     FROM Vote 
#     GROUP BY CandidateId 
#     HAVING COUNT(*)=(
#         SELECT COUNT(*) AS cnt
#         FROM Vote 
#         GROUP BY CandidateId
#         ORDER BY cnt DESC
#         LIMIT 1
#     )
# );

SELECT Name 
FROM Candidate 
WHERE id = (
    SELECT CandidateId 
    FROM Vote 
    GROUP BY CandidateId 
    ORDER BY COUNT(*) DESC
    LIMIT 1
);

