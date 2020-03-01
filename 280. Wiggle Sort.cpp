/*

280. Wiggle Sort -- Medium
http://www.leetcode-free.com/problems/wiggle-sort.html

Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].

*/


/*
无序数组，重新排列成中间大两边小的情况

顺序遍历数组，比较前后两个元素的大小关系：
如果i为偶数，那么希望是nums[i] <= nums[i+1]，一旦不满足上述条件，那么就交换nums[i]和nums[i+1]即可
如果i为奇数，那么希望是nums[i] >= nums[i+1], 一旦不满足上述条件，那么就交换nums[i]和nums[i+1]即可

*/
class Solution {  
public:  
    void wiggleSort(vector<int>& nums) {
    	int n = nums.size();
    	for(int i = 0; i < n-1; i++){
    		if((i%2==1 && nums[i]<nums[i+1]) || (i%2==0 && nums[i]>nums[i+1])){
    			// swap 
    			int tmp = nums[i];
    			nums[i] = nums[i+1];
    			nums[i+1] = tmp;
    		}
    	}
    } 
};  

