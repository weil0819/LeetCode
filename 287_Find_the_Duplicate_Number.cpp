//===========================================================================================
// 287. Find the Duplicate Number

// Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
// prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
// find the duplicate one.

// Note:
// You must not modify the array (assume the array is read only).
// You must use only constant, O(1) extra space.
// Your runtime complexity should be less than O(n2).
// There is only one duplicate number in the array, but it could be repeated more than once.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: 1)slow and fast points. Inspired by @echoxiaolee 
	* The main idea is the same with problem Linked List Cycle II,
	* https://leetcode.com/problems/linked-list-cycle-ii/. Use two pointers the fast and the slow. 
	* The fast one goes forward two steps each time, while the slow one goes only step each time. 
	* They must meet the same item when slow==fast. 
	* In fact, they meet in a circle, the duplicate number must be the entry point of the circle 
	* when visiting the array from nums[0]. Next we just need to find the entry point. 
	* We use a point(we can use the fast one before) to visit from begining with one step each time, 
	* do the same job to slow. When fast==slow, they meet at the entry point of the circle.
	* 
	* 2)binary search. Inspired by @mehran
	* At first the search space is numbers between 1 to n. 
	* Each time I select a number mid (which is the one in the middle) and 
	* count all the numbers equal to or less than mid. Then if the count is more than mid, 
	* the search space will be [1, mid] otherwise [mid+1, n]. 
	* I do this until search space is only one number.
	* 
	*/

	//Method-I:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast){
        	slow = nums[slow];
        	fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast){
        	fast = nums[fast];
        	slow = nums[slow];
        }
        return slow;
    }

    //Method-II:
    int findDuplicate(vector<int>& nums) {
    	int low = 1, high = nums.size()-1;
    	while(low < high){
    		int mid = low + (high-low)/2;			// compute the mid in [1, n-1]
    		int cnt = 0;
    		for(int i = 0; i < nums.size(); i++){	// count how many elements in array not larger than mid
    			if(nums[i] <= mid){
    				++cnt;
    			}    			
    		}
    		if(cnt <= mid){			// if cnt<=mid, that means the duplicated element must larger than mid
    			low = mid + 1;
    		}else{					// if cnt > mid, that means the duplicated element must smaller than mid
    			high = mid;
    		}
    	}
    	return low;
    }
};