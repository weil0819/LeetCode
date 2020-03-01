/*

360. Sort Transformed Array -- Medium
http://www.leetfree.com/problems/sort-transformed-array.html

Given a sorted array of integers nums and integer values a, b and c. 
Apply a quadratic function of the form f(x) = ax^2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]

*/

/*
已知二次方程和一组整数，将整数带入方程得到结果，并按照从小到大排序
*/
class Solution {
public:
	/*
	当a>0时,抛物线开口向上,这样给定的数组最大值肯定是在两端, 
	也就是要么在数组开始,要么在数组的最后, 这样我们可以依次取得最大值.最后的时候翻转一下数组即可.
	当a<0时, 抛物线开口向下,这样最小值肯定也是在两端, 我们可以依次在两端取最小值.
	*/
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
    	int n = nums.size();
    	if(n == 0) return {};
    	vector<int> res;
    	int left = 0, right = n-1;
    	while(left <= right) {
    		int val1 = func(nums[left], a, b, c), val2 = func(nums[right], a, b, c);
    		if(a > 0) res.push_back(val1 >= val2 ? val1 : val2);
    		if(a > 0) val1 >= val2 ? left++ : right--;
    		if(a <= 0) res.push_back(val1 >= val2 ? val2 : val1);
    		if(a <= 0) val1 >= val2 ? right-- : left++;
    	}
    	if(a > 0) reverse(res.begin(), res.end());	// if a > 0, it is in descending order
    	return res;
    }
private:
	int func(int x, int a, int b, int c){
		return a*power(x,2) + b*x + c;
	}
};