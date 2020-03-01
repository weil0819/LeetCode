/*

681. Next Closest Time -- Medium
http://www.leetfree.com/problems/next-closest-time.html

Given a time represented in the format “HH:MM”, 
form the next closest time by reusing the current digits. 
There is no limit on how many times a digit can be reused.

You may assume the given input string is always valid. 
For example, “01:34”, “12:09” are all valid. “1:34”, “12:9” are all invalid.

Example 1:

Input: “19:34” 
Output: “19:39” 
Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, 
which occurs 5 minutes later. It is not 19:33, because this occurs 23 hours and 59 minutes later.

Example 2:

Input: “23:59” 
Output: “22:22” 
Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. 
It may be assumed that the returned time is next day’s time since it is smaller than the input time numerically.

*/

class Solution {
public:
	/*
	使用digits存放给定的时间的数字
	从第4位开始，在digits中找有没有比第4位的数更大的数字，如果有则直接返回
	继续第3-2-1位，在digits找有没有比相应数更大的数字，
	如果直到第1位还找不到，那么就直接将四位都设置成最小值
	*/
    string nextClosestTime(string time) {
    	vector<int> digits(10, 0);
    	char min = '9';
    	for(int i = 0; i < time.size(); i++){
    		if(time[i] == ':') continue ;
    		digits[time[i]-'0']++;
    		if(time[i] < min){
    			min = time[i];					// find the min digit in time
    		}
    	}

    	// scan the 4-th digit
    	for(int i = time[4]-'0'+1; i <= 9; i++){
    		if(digits[i] != 0){
    			time[4] = (char)digits[i];
    			return time;
    		}
    	}
    	time[4] = min;				// set the min digit

    	// scan the 3-th digit
    	for(int i = time[3]-'0'+1; i <= 5; i++){
    		if(digits[i] != 0){
    			time[3] = (char)digits[i];
    			return time;
    		}
    	}
		time[3] = min;				// set the min digit

    	// scan the 2-th digit
    	int stop = time[0] < '2' ? 9 : 3;
    	for(int i = time[1]-'0'+1; i <= stop; i++){
    		if(digits[i] != 0){
    			time[1] = (char)digits[i];
    			return time;
    		}
    	}
    	time[1] = min;				// set the min digit

    	// scan the 1-th digit
    	for(int i = time[0]-'0'+1; i <= 2; i++){
    		if(digits[i] != 0){
    			time[0] = (char)digits[i];
    			return time;
    		}
    	}  
    	time[0] = min;				// set the min digit

    	return time;
    }
};