/*
601. Human Traffic of Stadium
https://leetcode.com/problems/human-traffic-of-stadium/description/

X city built a new stadium, each day many people visit it and the stats are saved as these columns: id, date, people

Please write a query to display the records which have 3 or more consecutive rows and the amount of people more than 100(inclusive).

For example, the table stadium:
+------+------------+-----------+
| id   | date       | people    |
+------+------------+-----------+
| 1    | 2017-01-01 | 10        |
| 2    | 2017-01-02 | 109       |
| 3    | 2017-01-03 | 150       |
| 4    | 2017-01-04 | 99        |
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-08 | 188       |
+------+------------+-----------+
For the sample data above, the output is:

+------+------------+-----------+
| id   | date       | people    |
+------+------------+-----------+
| 5    | 2017-01-05 | 145       |
| 6    | 2017-01-06 | 1455      |
| 7    | 2017-01-07 | 199       |
| 8    | 2017-01-08 | 188       |
+------+------------+-----------+
Note:
Each day only have one row record, and the dates are increasing with id increasing.

*/

# Write your MySQL query statement below
# for consecutive problem, self join
select distinct S1.* 
from stadium S1, stadium S2, stadium S3
where S1.people >= 100 and S2.people >= 100 and S3.people >= 100 and (
        (S1.id - S2.id = 1 and S1.id - S3.id = 2 and S2.id - S3.id = 1) or # S1-S2-S3
        (S2.id - S1.id = 1 and S2.id - S3.id = 2 and S1.id - S3.id = 1) or # S2-S1-S3
        (S3.id - S2.id = 1 and S3.id - S1.id = 2 and S2.id - S1.id = 1)    # S3-S2-S1        
        )
order by S1.id;
