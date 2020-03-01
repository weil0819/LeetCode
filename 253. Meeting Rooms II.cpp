/*

253. Meeting Rooms II -- Medium
http://www.leetcode-free.com/problems/meeting-rooms-ii.html

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), 
find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

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
	/*
	建立start和end两个数组
	分别对start和end两个数组排序
	如果start[i] < end[index]，那么就需要一个新room，index是最近的结束时间
	否则我们可以在index位置的interval结束之后利用它的room即可
	*/
    int minMeetingRooms(vector<Interval>& intervals) {
    	int n = intervals.size();
    	if(n == 0) return 0;
    	vector<int> startVec, endVec;
    	for(int i = 0; i < n; i++){
    		startVec.push_back(intervals[i].start);
    		endVec.push_back(intervlas[i].end);
    	}
    	sort(startVec.begin(), startVec.end());		//O(nlogn)
    	sort(endVec.begin(), endVec.end());

    	int index = 0, ans = 0;
    	for(int i = 0; i < n; i++){
    		if(startVec[i] < endVec[index]) ans++;	// new room
    		else index++;							// old room
    	}
    	return ans;
    }
};