/*

163. Missing Ranges -- Medium
http://www.leetfree.com/problems/missing-ranges.html


Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], 
return its missing ranges.

Example:

Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
Output: ["2", "4->49", "51->74", "76->99"]

*/

class Solution {  
public:  
	/*

	O(N)时间遍历数组，如果nums[i] > lower，那么[lower,nums[i]-1]这个范围就需要补充进来
	然后更新lower = nums[i]+1
	
	最后比较lower与upper的值

	*/
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {  
    	vector<string> ans;
    	int n = nums.size();
    	if(n == 0) {
    		string str = "";
    		if(lower == upper) {
    			str = "" + lower;
    		}else{
    			str = lower + "->" + upper;
    		}
    		ans.push_back(str);
    		return ans;
    	}

    	int i = 0;
    	while(i < n){
    		if(nums[i] > lower){
    			string str = "";
    			if(lower+1 == nums[i]){
    				str = "" + lower;
    			}else{
    				str = lower + "->" + (nums[i]-1);
    			}
    			ans.push_back(str);
    		}
    		lower = nums[i]+1;		// update "lower"
    		i++;
    	}

    	// compare "lower" and "upper"
    	if(lower == upper){
    		string str = "" + lower;
    		ans.push_back(str);
    	}else{
    		string str = "";
    		str = lower + "->" + (nums[i]-1);
    		ans.push_back(str);
    	}
    	return ans;
    }   
};