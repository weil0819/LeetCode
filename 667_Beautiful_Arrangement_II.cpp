//==========================================================================================
// 667. Beautiful Arrangement II

// Given two integers n and k, you need to construct a list which contains n different positive integers 
// ranging from 1 to n and obeys the following requirement: 
// Suppose this list is [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] 
// has exactly k distinct integers.

// If there are multiple answers, print any of them.

// Example 1:
// Input: n = 3, k = 1
// Output: [1, 2, 3]
// Explanation: The [1, 2, 3] has three different positive integers ranging from 1 to 3, 
// and the [1, 1] has exactly 1 distinct integer: 1.
// Example 2:
// Input: n = 3, k = 2
// Output: [1, 3, 2]
// Explanation: The [1, 3, 2] has three different positive integers ranging from 1 to 3, 
// and the [2, 1] has exactly 2 distinct integers: 1 and 2.
// Note:
// The n and k are in the range 1 <= k < n <= 104.
//==========================================================================================
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: There are n numbers, k is at most n-1, eg,
	* 1 2 3 4 5 6 7 8 9 ==> 1 9 2 8 3 7 4 6 5 ==> dif=[8,7,6,5,4,3,2,1]
	* When k != n-1, we only generate dif as followings: dif=[n-1, n-2,..., n-k+1, 1,...,1]
	* eg, when k=5, 1 9 2 8 3 4 5 6 7 ==> dif=[8,7,6,5,1,1,1,1]
	*     when k=6, 9 1 8 2 7 3 4 5 6 ==> dif=[8,7,6,5,4,1,1,1]
	* Time complexity = O(n), space complexity = O(n)
	* 
	* Here, we use two points i and j to point to the head and tail of array
	* when dif==k, put all remaining elements in array sequentially.
	* 
	*/
    vector<int> constructArray(int n, int k) {
        vector<int> output;
        if(k == 1){
        	for(int i = 1; i <= n; i++){
        		output.push_back(i);
        	}
        	return output;
        }

        int i = 1, j = n;
        while(k > 1 && i <= j){
        	if(k % 2 == 0){
        		output.push_back(j);
        		j--;
        	}else{
        		output.push_back(i);
        		i++;
        	}
        	k--;        	
        }
        while(i <= j){
        	output.push_back(i);
        	i++;
        }
        return output;
    }
};


int main(){
	Solution sn;
	vector<int> output = sn.constructArray(9, 6);
	for(int i = 0; i < output.size(); i++){
		cout<<output[i]<<endl;
	}
	return 0;
}