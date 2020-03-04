/*
621. Task Scheduler -- Medium
https://leetcode.com/problems/task-scheduler/ 

@date: Mon 2 Mar. 2020 

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

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
    // Use hashmap to record <char, #char>
    // Sort hashmap in ascending order by #char
    // Scan each char in descending order by #char
    // Insert interval in ascending order by #char
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> help(26);       // <char, #char>
        for(char c: tasks) {
            help[c-'A']++;
        }
        
        sort(help.begin(), help.end()); // small-->large
        
        int res = 0;
        while(help[25] > 0) {       // consider the longest char first
            int i = 0;
            while(i <= n) {
                if(help[25] == 0) break;
                if(i < 26 && help[25-i] > 0) {
                    help[25-i]--;
                }
                res++;              // insert one char
                i++;
            }
            sort(help.begin(),help.end());  // re-order the hashmap
        }
        
        return res;        
    }
};

