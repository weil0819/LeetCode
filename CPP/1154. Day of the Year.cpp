/*

1154. Day of the Year -- Easy 
https://leetcode.com/problems/ordinal-number-of-date/ 

Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

 

Example 1:

Input: date = "2019-01-09"
Output: 9
Explanation: Given date is the 9th day of the year in 2019.
Example 2:

Input: date = "2019-02-10"
Output: 41
Example 3:

Input: date = "2003-03-01"
Output: 60
Example 4:

Input: date = "2004-03-01"
Output: 61
 

Constraints:

date.length == 10
date[4] == date[7] == '-', and all other date[i]'s are digits
date represents a calendar date between Jan 1st, 1900 and Dec 31, 2019.

*/

class Solution {
public:
    int dayOfYear(string date) {
        // get year, month, day from string (stoi)
        int year = stoi(date.substr(0,4));
        int month = stoi(date.substr(5,2));
        int day = stoi(date.substr(8,2));
        
        int res = 0;
        res += day;
        for(int i = 1; i < month; i++) {
            if(i == 1 || i == 3 || i == 5 || i == 7 || i ==8 || i == 10 || i == 12) res += 31;
            else if(i == 4 || i == 6 || i == 9 || i == 11) res += 30;
            else res += 28;
        }
        
        res += (month > 2 && (year % 4 == 0 && year % 100 != 0)) ? 1 : 0;
        
        return res;        
    }
};


