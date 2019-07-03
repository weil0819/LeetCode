/*
578. Get Highest Answer Rate Question
https://www.leetfree.com/problems/get-highest-answer-rate-question.html

Get the highest answer rate question from a table survey_log with these columns: uid, action, question_id, answer_id, q_num, timestamp.

uid means user id; action has these kind of values: "show", "answer", "skip"; answer_id is not null when action column is "answer", while is null for "show" and "skip"; q_num is the numeral order of the question in current session.

Write a sql query to identify the question which has the highest answer rate.

Example:
Input:
+------+-----------+--------------+------------+-----------+------------+
| uid  | action    | question_id  | answer_id  | q_num     | timestamp  |
+------+-----------+--------------+------------+-----------+------------+
| 5    | show      | 285          | null       | 1         | 123        |
| 5    | answer    | 285          | 124124     | 1         | 124        |
| 5    | show      | 369          | null       | 2         | 125        |
| 5    | skip      | 369          | null       | 2         | 126        |
+------+-----------+--------------+------------+-----------+------------+

Output:
+-------------+
| survey_log  |
+-------------+
|    285      |
+-------------+

Explanation:
question 285 has answer rate 1/1, while question 369 has 0/1 answer rate, so output 285.

Note: The highest answer rate meaning is: answer number's ratio in show number in the same question.

*/

# Write your MySQL query statement below
# Answer Rate = answered times / show times

# return the number of answared times and show times for each question
select question_id, sum(case when action = "answer" then 1 else 0 end) as num_answer, 
                    sum(case when action = "show" then 1 else 0 end) as num_show
from survey_log 
group by question_id
;

# return Answer Rate
select question_id as survey_log 
from (
        select question_id, sum(case when action = "answer" then 1 else 0 end) as num_answer, 
                    sum(case when action = "show" then 1 else 0 end) as num_show
        from survey_log 
        group by question_id
     ) as table
order by (num_answer/num_show) desc     # order by Answer Rate in descending order
limit 1                                 # only return one result
;

