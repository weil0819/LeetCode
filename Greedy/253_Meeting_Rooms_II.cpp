/*
253. Meeting Rooms II -- Medium
https://leetcode.com/problems/meeting-rooms-ii/

@date: Mon 2 Mar. 2020

Given an array of meeting time intervals consisting of start 
and end times [[s1,e1],[s2,e2],...] (si < ei), 
find the minimum number of conference rooms required.

Example 1:

Input: [[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:

Input: [[7,10],[2,4]]
Output: 1

NOTE: input types have been changed on April 15, 2019. 
Please reset to default code definition to get new method signature.

*/


bool myComp(vector<int>& A, vector<int>& B) {
    return A[0] < B[0];
}

class Solution {
public:
    // Sort intervals in ascending order by start
    // Use priority_queue to store new merged interval, i.e., rooms
    // Insert end time into priority_queue
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int N = intervals.size();
        if(N <= 1) return N;
        
        // Sorting ... [[4,9], [4,17], [9,10]]
        sort(intervals.begin(), intervals.end(), myComp);
        
        priority_queue<int, vector<int>, greater<int> > min_heap;   // rooms
        
        min_heap.push(intervals[0][1]);
        
        for(int i = 1; i < N; i++) {
            int minEnd = min_heap.top();            // find the minimum end time
            min_heap.pop();
            if(intervals[i][0] >= minEnd) {         // start >= end, merge them
                minEnd = intervals[i][1];           // merge two intervals
            }else min_heap.push(intervals[i][1]);   // insert new room
            
            min_heap.push(minEnd);                  // update old room
        }
        
        return min_heap.size();
    }
};

