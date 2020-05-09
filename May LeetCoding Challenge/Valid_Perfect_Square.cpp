/*
Valid Perfect Square

@date: May 9, 2020

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false

*/


class Solution {
public:
    // Binary Search    
    /*
    bool isPerfectSquare(int num) {
        if(num == 1) return true;
        
        long long int left = 1, right = num;
        while(left <= right) {
            long long int mid = left + (right-left)/2;
            if(mid * mid == num) return true;
            else if(mid * mid < num) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
    */
    
    // Math: A square number is 1+3+5+7+...
    // Let "num" minus 1, 3, 5, ... until arrive 0
    bool isPerfectSquare(int num) {
        int temp = 1;
        while(num > 0) {
            num -= temp;
            temp += 2;            
        }
        return num == 0;
    }
};
