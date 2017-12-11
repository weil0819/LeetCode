//===========================================================================================
// 646. Maximum Length of Pair Chain

// You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

// Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

// Given a set of pairs, find the length longest chain which can be formed. 
// You needn't use up all the given pairs. You can select pairs in any order.

// Example 1:
// Input: [[1,2], [2,3], [3,4]]
// Output: 2
// Explanation: The longest chain is [1,2] -> [3,4]
// Note:
// The number of given pairs will be in the range [1, 1000].
//===========================================================================================
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
    return a[1] < b[1];
}
class Solution {
public:
	/**
	* Idea: 1) sort the pairs according to the right value, and then scan this array
	* 2) we can also use dynamic programming method by dp[i] standing for the longest chain in pairs[0] to pairs[i]
	* that is, dp[i] = max(dp[i], pairs[i][0] > pairs[j][1] ? dp[j] + 1 : dp[j]) where j < i
	* 
	*/
	// Method-I:
	/*
    int findLongestChain(vector<vector<int> >& pairs) {
    	if(pairs.size() == 0){
    		return 0;
    	}
        sort(pairs.begin(), pairs.end(), cmp);
        int res = 1, end = pairs[0][1];
        for(int i = 1; i < pairs.size(); i++){
        	if(pairs[i][0] > end){
        		++res;
        		end = pairs[i][1];
        	}
        }
        return res;
    }
    */

	// Method-II:
    int findLongestChain(vector<vector<int> >& pairs) {
    	if(pairs.size() == 0){
    		return 0;
    	}
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> dp(pairs.size(), 1);
        for(int i = 0; i < pairs.size(); i++){
        	for(int j = 0; j < i; j++){
        		dp[i] = max(dp[i], pairs[i][0] > pairs[j][1] ? dp[j] + 1 : dp[j]);
        	}
        }
        return dp[pairs.size()-1];
    }

};


int main(){
	Solution sn;
	int a[] = {1,2};
	int b[] = {2,3};
	int c[] = {3,4};
	vector<vector<int> > pairs;
	pairs.push_back(vector<int>(a, a+2));
	pairs.push_back(vector<int>(b, b+2));
	pairs.push_back(vector<int>(c, c+2));
	cout<<sn.findLongestChain(pairs)<<endl;

	return 0;
}