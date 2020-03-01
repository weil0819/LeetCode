/*

621. Task Scheduler -- Medium
https://leetcode.com/problems/task-scheduler/

Given a char array representing tasks CPU need to do. 
It contains capital letters A to Z where different letters represent different tasks. 
Tasks could be done without original order. Each task could be done in one interval. 
For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, 
there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 

Note:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].

*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // count how many time does each char appear
        vector<int> map(26);
        for(char c: tasks) {
            map[c-'A']++;
        }
        
        // sort the map in ascending order
        sort(map.begin(), map.end());
        
        // sacn each char in descending order
        int res = 0;
        while(map[25] > 0) {    // consider the longest char first
            int i = 0;
            while(i <= n) {     // insert n different chars
                if(map[25] == 0) break;
                // insert interval in ascending order
                if(i < 26 && map[25-i] > 0) {
                    map[25-i]--;
                }
                // if map[25-i] not exists, we need insert idle in order to keep n intervals
                res++;
                i++;
            }
            // re-order the map
            sort(map.begin(), map.end());
        }
        return res;
    }
};

