//===========================================================================================
// 400. Nth Digit
// Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

// Note:	
// n is positive and will fit within the range of a 32-bit signed integer (n < 231).

// Example 1:

// Input:
// 3

// Output:
// 3

// Example 2:

// Input:
// 11

// Output:
// 0

// Explanation:
// The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
//===========================================================================================
#include <iostream>
using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // 9*1, 90*2, 900*3, 9000*4
        int len = 1, start = 1;
        long carry = 9;
        while(n > len*carry){
        	n -= len*carry;
        	len++;
        	carry *= 10;
        	start *= 10;
        	cout<<"carry = "<<carry<<", start = "<<start<<endl;
        }

        cout<<"n = "<<n<<", start = "<<start<<endl;

        start = start + n/len - 1;			// 11/3=3...2==>100101102,10
        if(n%len == 0){
        	return start%10;
        }else{
        	int tmp = len - n%len;
        	start += 1;
        	while(tmp > 0){
        		start = start/10;
        		tmp--;
        	} 
        	return start%10;       	
        }

    }
};

int main(){
	Solution sn;

	cout<<sn.findNthDigit(1000000000)<<endl;
	return 0;
}
