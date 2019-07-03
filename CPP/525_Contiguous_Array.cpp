//===========================================================================================
// Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

// Example 1:
// Input: [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
// Example 2:
// Input: [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
// Note: The length of the given binary array will not exceed 50,000.
//===========================================================================================


class Solution {
public:
	/**
	* Idea: we should count the dif between #0 and #1
    * and use a unordered_map<int, int> to record the <dif, pos>
    * 
	*/
    int findMaxLength(vector<int>& nums) {
    	int n = nums.size();
    	if(n < 2){
    		return 0;
    	}
        unordered_map<int, int> helper;
        helper.insert(make_pair(0,-1));     // if dif=0, we len of contiguous subarray + 1
        int res = 0, dif = 0;
        for(int i = 0; i < n; i++){
        	dif += (nums[i]==0) ? -1 : 1;
        	if(helper.find(dif) != helper.end()){
                // we can determine the subarray between helper.find(dif)->second and i is contiguous subarray
        		res = max(res, i-helper.find(dif)->second);         
        	}else{
        		helper.insert(make_pair(dif, i));
        	}
        }
        return res;
    }
};
