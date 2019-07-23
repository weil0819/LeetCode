/*
178. Rank Scores -- Easy
https://leetcode.com/problems/rank-scores/

Write a SQL query to rank scores. If there is a tie between two scores, both should have the same ranking. Note that after a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no "holes" between ranks.

+----+-------+
| Id | Score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+

For example, given the above Scores table, your query should generate the following report (order by highest score):

+-------+------+
| Score | Rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+

*/

# Write your MySQL query statement below

# return different score in Scores
select distinct Score from Scores;

# return how many unique score no less than current score
select count(*) from (select distinct Score S from Scores) as tmp where S >= score;

# return rank
select Score, (select count(*) 
               from (select distinct Score S from Scores) as tmp 
               where S >= Score) as Rank
from Scores
order by Score desc
;

