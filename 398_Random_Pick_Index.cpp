//===========================================================================================
// 398. Random Pick Index

// Given an array of integers with possible duplicates, randomly output the index of a given target number. 
// You can assume that the given target number must exist in the array.

// Note:
// The array size can be very large. Solution that uses too much extra space will not pass the judge.

// Example:

// int[] nums = new int[] {1,2,3,3,3};
// Solution solution = new Solution(nums);

// // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
// solution.pick(3);

// // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
// solution.pick(1);
//===========================================================================================

/**
* Idea: how to use rand() function
* we need count the number of indices which has value target
* Attention: the indices which has target value may be unsorted
* 
*/
class Solution {
private:
	vector<int> _nums;
public:
    Solution(vector<int> nums) {
        _nums = nums;
    }
    
    int pick(int target) {
    	int cnt = 0, start = -1;
    	vector<int> index;
        for(int i = 0; i < _nums.size(); i++){
        	if(_nums[i] != target){
        		continue ;
        	}else{
        		index.push_back(i);
        		++cnt;
        	}
        }
        return index[rand()%(index.size())];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
