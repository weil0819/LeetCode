//===========================================================================================
// 670. Maximum Swap

// Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. 
// Return the maximum valued number you could get.

// Example 1:
// Input: 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
// Example 2:
// Input: 9973
// Output: 9973
// Explanation: No swap.
// Note:
// The given number is in the range [0, 108]
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a backtracking problem
	* 
	*/
    int maximumSwap(int num) {
    	int res = num;
        stack<int> helper;
        while(num > 0){
        	helper.push(num % 10);
        	num /= 10;
        }
        vector<int> vec;
        while(!helper.empty()){
        	vec.push_back(helper.top());
        	helper.pop();
        }
        int n = vec.size();
        
        for(int i = 0; i < n-1; i++){
        	for(int j = i+1; j < n; j++){
        		if(vec[i] < vec[j]){
        			swap(vec[i], vec[j]);
        			int tmp = 0, cnt = 1;
        			for(int k = vec.size()-1; k >= 0; k--){
        				tmp = vec[k]*cnt +tmp;
        				cnt *= 10;
        			}
        			swap(vec[j], vec[i]);
        			if(tmp > res){
        				res = tmp;
        			}
        		}
        	}
        }
        return res;
    }
};
