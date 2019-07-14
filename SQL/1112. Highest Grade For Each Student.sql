/*

1112. Highest Grade For Each Student -- Medium
https://leetcode.com/problems/highest-grade-for-each-student/

Table: Enrollments

+---------------+---------+
| Column Name   | Type    |
+---------------+---------+
| student_id    | int     |
| course_id     | int     |
| grade         | int     |
+---------------+---------+
(student_id, course_id) is the primary key of this table.

Write a SQL query to find the highest grade with its corresponding course for each student. 
In case of a tie, you should find the course with the smallest course_id. 
The output must be sorted by increasing student_id.

The query result format is in the following example:

Enrollments table:
+------------+-------------------+
| student_id | course_id | grade |
+------------+-----------+-------+
| 2          | 2         | 95    |
| 2          | 3         | 95    |
| 1          | 1         | 90    |
| 1          | 2         | 99    |
| 3          | 1         | 80    |
| 3          | 2         | 75    |
| 3          | 3         | 82    |
+------------+-----------+-------+

Result table:
+------------+-------------------+
| student_id | course_id | grade |
+------------+-----------+-------+
| 1          | 2         | 99    |
| 2          | 2         | 95    |
| 3          | 3         | 82    |
+------------+-----------+-------+

*/

# Write your MySQL query statement below
SELECT E.student_id, MIN(E.course_id) AS course_id, E.grade 
FROM Enrollments E 
WHERE (E.student_id,E.grade) IN (
    SELECT student_id,MAX(grade) 
    FROM Enrollments 
    GROUP BY student_id
) 
GROUP BY E.student_id,E.grade
ORDER BY E.student_id
;


