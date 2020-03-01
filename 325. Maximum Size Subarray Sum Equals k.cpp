/*
325. Maximum Size Subarray Sum Equals k -- Medium
https://www.leetfree.com/problems/maximum-size-subarray-sum-equals-k.html
http://www.cnblogs.com/grandyang/p/5336668.html

Given an array nums and a target value k, find the maximum length of a subarray that sums to k. 
If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?

*/

// Approach #1: subarray should be contiguous
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int sum = 0, res = 0;
        unordered_map<int, int> m;		// <sum, index>
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum == k) res = i + 1;	// from 0 to i
            else if (m.count(sum - k)) res = max(res, i - m[sum - k]);	// from m[sum-k] to i
            if (!m.count(sum)) m[sum] = i;	// record new sum value
        }
        return res;
    }
};

// Approach #2: 
class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int res = 0;
        unordered_map<int, vector<int>> m;
        m[nums[0]].push_back(0);
        vector<int> sum = nums;
        for (int i = 1; i < nums.size(); ++i) {
            sum[i] += sum[i - 1];
            m[sum[i]].push_back(i);
        }
        for (auto it : m) {
            if (it.first == k) res = max(res, it.second.back() + 1);
            else if (m.find(it.first - k) != m.end()) {
                res = max(res, it.second.back() - m[it.first - k][0]);
            }
        }
        return res;
    }
};

