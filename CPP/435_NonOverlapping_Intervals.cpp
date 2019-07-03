//===========================================================================================
// 435. Non-overlapping Intervals

// Given a collection of intervals, find the minimum number of intervals you need to 
// remove to make the rest of the intervals non-overlapping.

// Note:
// You may assume the interval's end point is always bigger than its start point.
// Intervals like [1,2] and [2,3] have borders "touching" but they don't overlap each other.
// Example 1:
// Input: [ [1,2], [2,3], [3,4], [1,3] ]

// Output: 1

// Explanation: [1,3] can be removed and the rest of intervals are non-overlapping.
// Example 2:
// Input: [ [1,2], [1,2], [1,2] ]

// Output: 2

// Explanation: You need to remove two [1,2] to make the rest of intervals non-overlapping.
// Example 3:
// Input: [ [1,2], [2,3] ]

// Output: 0

// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
//===========================================================================================

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool myCompare(Interval in1, Interval in2){
	if(in1.start < in2.start){
		return true;
	}else if(in1.start == in2.start && in1.end < in2.end){
		return true;
	}else{
		return false;
	}
}

bool myComp(Interval in1, Interval in2){
	return in1.start < in2.start;
}


class Solution {
public:
	/**
	* Idea: we first sort the vector according to "start"
	* and then traverse the vector to compare the "end" of previous one and "start" of current one
	* 
	*/
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0){
        	return 0;
        }

        sort(intervals.begin(), intervals.end(), myComp);
        int preEnd = intervals[0].end, res = 0;
        for(int i = 1; i < n; i++){
        	if(intervals[i].start < preEnd){
        		++res;    
        		if(intervals[i].end < preEnd){		// [1,5], [2,3], [3,4], [4,5]
        			preEnd = intervals[i].end;		// here we hope preEnd to be as small as possible
        		}   								// remove [1,5], not [2,3]
        	}else{
        		preEnd = intervals[i].end;
        	}
        }
        return res;
    }
};



