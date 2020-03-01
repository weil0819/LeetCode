/*

57. Insert Interval
https://leetcode.com/problems/insert-interval/description/

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    /**
    * Idea: this is a Array problem
    * for index i where interval[i].end < newInterval.start, we can push it into res
    * after that, for index i where intervals[i].start <= newInterval.end, we build a new Interval
    * and then, we push all remaining indices
    * 
    * time complexity: O(N)
    * space complexity: O(1)
    * 
    */
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int startInd = 0, endInd = 0;
        int n = intervals.size();
        vector<Interval> res;
        if(n == 0){
            res.push_back(newInterval);
            return res;
        }
        int index = 0;
        while(index < n && intervals[index].end < newInterval.start){
            res.push_back(intervals[index++]);
        }
        while(index < n && intervals[index].start <= newInterval.end){
            newInterval.start = min(newInterval.start, intervals[index].start);
            newInterval.end = max(newInterval.end, intervals[index].end);
            index++;
        }
        res.push_back(newInterval);
        while(index < n){
            res.push_back(intervals[index++]);
        }
        return res;
    }
};