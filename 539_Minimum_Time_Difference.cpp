//===========================================================================================
// 539. Minimum Time Difference

// Given a list of 24-hour clock time points in "Hour:Minutes" format, 
// find the minimum minutes difference between any two time points in the list.

// Example 1:
// Input: ["23:59","00:00"]
// Output: 1
// Note:
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.
//===========================================================================================
#include <iostream>
#include <vector>
#include <string.h>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
	/**
	* Idea: we can sort the array and then make comparison from 0 to last but not least one
	* and then compare the last one with the first one
	* 
	*/
    int findMinDifference(vector<string>& timePoints) {
    	int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int minMin = INT_MAX, next = 0;
        for(int i = 0; i < n-1; i++){
        	int h1 = stoi(timePoints[i].substr(0, 2));
        	int m1 = stoi(timePoints[i].substr(3, 2));
        	int sum1 = h1*60 + m1;
        	int h2 = stoi(timePoints[i+1].substr(0, 2));
        	int m2 = stoi(timePoints[i+1].substr(3, 2));
        	int sum2 = h2*60 + m2;
        	minMin = min(minMin, abs(sum2-sum1));   
        }
        int sumFir = stoi(timePoints[0].substr(0, 2))*60 + stoi(timePoints[0].substr(3, 2));
        int sumLast = stoi(timePoints[n-1].substr(0, 2))*60 + stoi(timePoints[n-1].substr(3, 2));
        minMin = min(minMin, 24*60 - abs(sumLast-sumFir));
        return minMin;
    }
};

int main(){
	Solution sn;
	vector<string> timePoints;
	// timePoints.push_back("00:00");
	// timePoints.push_back("23:59");
	// timePoints.push_back("00:00");

	// timePoints.push_back("12:12");
	// timePoints.push_back("00:13");	

	timePoints.push_back("05:31");
	timePoints.push_back("22:08");	
	timePoints.push_back("00:35");
	cout<<sn.findMinDifference(timePoints)<<endl;
	return 0;
}