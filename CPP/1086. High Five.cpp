/*

1086. High Five -- Easy 
https://leetcode.com/problems/high-five/ 

Given a list of scores of different students, return the average score of each student's top five scores 
in the order of each student's id.

Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  
The average score is calculated using integer division.

 

Example 1:

Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.
 

Note:

1 <= items.length <= 1000
items[i].length == 2
The IDs of the students is between 1 to 1000
The score of the students is between 1 to 100
For each student, there are at least 5 scores

*/

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        map<int, vector<int> > help;    // <ID, score set>        
        vector<vector<int> > res;
        for(auto item: items) {
            help[item[0]].push_back(item[1]);
        }
        
        res.resize(help.size());

        int i = 0;
        for(auto stu: help) {
            // sort score set for ech student ID in ascending order
            sort(stu.second.begin(), stu.second.end(), greater<int>());
            res[i].push_back(stu.first);
            int sum = stu.second[0]+stu.second[1]+stu.second[2]+stu.second[3]+stu.second[4];
            res[i].push_back((int)sum/5);
            i++;
        }

        return res;
    }
};
