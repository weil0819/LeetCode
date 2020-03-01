//===========================================================================================
// 69. Sqrt(x)

// Implement int sqrt(int x).

// Compute and return the square root of x.
//===========================================================================================
#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
	/**
	* Idea: binary search
	* 
	*/
    int mySqrt(int x) {
    	if(x < 2){
    		return x;
    	}
        int low = 0, high = x;
        while(low <= high){
        	int mid = (low+high)/2;
        	if(mid < x/mid){
        		low = mid+1;
        	}else if(mid > x/mid){
        		high = mid-1;
        	}else{
        		return mid;
        	}
        }
        return high;
    }
};

int main(){
	Solution sn;
	cout<<sn.mySqrt(8)<<endl;
	cout<<(int)sqrt(8)<<endl;
	return 0;
}

