/*

252. Meeting Rooms -- Easy
https://www.leetfree.com/problems/meeting-rooms.html

Given an array of meeting time intervals consisting of start and 
end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.

*/

/*
问题：已知一组会议的时间间隔，判断一个人是否可以参加所有的会议


如果每个间隔相互之间不重叠，那么就可以参加所有
所以，首先对时间间隔排序，按照si由小到大
然后，定义一个变量last表示前面的end时间，
顺序遍历排序后的时间间隔，如果intervals[i].start < last，那么就返回false；否则更新last = intervals[i].end

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

bool myCmp(Interval& i, Interval& j){
	if(i.start < j.start || (i.start == j.start && i.end < j.end)){
		return true;
	}
	return false;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
    	int n = intervals.size();
    	if(n == 0) return true;		// if no interval, a person can attend
    	sort(intervals.begin(), intervals.end(), myCmp);

    	int last = intervals[0].end;
    	for(int i = 1; i < n; i++){
    		if(intervals[i].start < last){
    			return false;
    		}
    		last = intervals[i].end;		// update "last"
    	}
    	return true;
    }
};