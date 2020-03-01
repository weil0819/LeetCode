/*

644. Maximum Average Subarray II -- Hard
http://www.leetfree.com/problems/maximum-average-subarray-ii.html

Given an array consisting of n integers, 
find the contiguous subarray whose length is greater than or equal to k that has the maximum average value. 
And you need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.
Note:
1 <= k <= n <= 10,000.
Elements of the given array will be in range [-10,000, 10,000].
The answer with the calculation error less than 10-5 will be accepted.

*/

/*
已知一个长度为n的数组，寻找长度>=k的子数组，并且该子数组的平均值最大
*/

class Solution {
public:
	/*
	首先找出数组中的最小值left和最大值right，因为这将构成最大平均值的区间。
	然后每次找到left和right的平均值mid，对于mid，在数组内找是否存在一个长度大于等于k的连续区间，
	其平均值大于mid，如果存在，那么说明mid还不是最大平均值，所以修改左边界left；
	否则说明mid已经大于等于左右长度大于等于k的所有连续区间的最大平均值了，所以此时修改右边界right。
	这样当left和right逐渐收敛到一点的时候，该收敛点就是最大平均值。

	该算法的空间复杂度是O(1)，时间复杂度是O(logm*n)，其中n是nums的长度，
	而m则是nums中最大值和最小值的差。虽然m有可能很大，但是被log了，所以该时间复杂度接近于O(n)
	*/
    double findMaxAverage(vector<int>& nums, int k) {
        double left = INT_MAX, right = INT_MIN, mid;
        for (int num : nums) {
            right = max(right, double(num));    // the max value in the array
            left = min(left, double(num));      // the min value in the array
        }
        while (left + 0.00001 < right) {        //threshold
            mid = left + (right - left) / 2;
            if(islarger(nums, mid, k)) {
                right = mid;
            }
            else {
                left = mid;
            }
        }
        return left;
    }
private:
    // Return true when mid is larger than or equal to the maximum average value;
    // Return false when mid is smaller than the maximum average value.
    bool islarger(vector<int>& nums, double mid, int k){
        // sum: the sum from nums[0] to nums[i];
        // prev_sum:  the sum from nums[0] to nums[i-k];
        // min_sum: the minimal sum from nums[0] to nums[j] ( 0=< j <= i-k );
        double sum = 0, prev_sum = 0, min_sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i] - mid;
            if (i >= k) {
                prev_sum += nums[i-k] - mid;                        
                min_sum = min(prev_sum, min_sum); 
            }
            if(i >= k-1 && sum > min_sum) { // there exists an range in which the average value is larger
                return false;
            }
        }
        return true;                                               
    }
};