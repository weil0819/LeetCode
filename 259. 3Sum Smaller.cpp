/*
259. 3Sum Smaller -- Medium
https://www.leetfree.com/problems/3sum-smaller.html

Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n 
that satisfy the condition nums[i] + nums[j] + nums[k] < target.

For example, given nums = [-2, 0, 1, 3], and target = 2.

Return 2. Because there are two triplets which sums are less than 2:

[-2, 0, 1]
[-2, 0, 3]

Follow up:
Could you solve it in O(n^2) runtime?

*/

/*
已知长度为n的数组和一个目标值target，求3个索引值使得累加和小于target
*/
class Solution {
public:
    /*
    首先对数据按照升序排序
    i,j,k为3个索引值，那么顺序遍历i值，然后设定j=i+1,k=n-1
    计算累加和并与target比较
    如果sum < target，那么位于j和k之间的所有索引值都可以认为是k，因为数组是有序的
    如果sum >= target，那么就减小k值
    */
    int threeSumSmaller(vector<int>& nums, int target){
        int n = nums.size();
        if(n < 3) return 0;
        sort(nums.begin(), nums.end());     // sort the array in ascending order

        int sum = nums[0] + nums[1] + nums[2];
        if(sum >= target) return 0;

        int ans = 0;
        for(int i = 0; i < n-2; i++){       // scan each i from 0 to n-2
            int j = i+1, k = n-1;           // make j=i+1, k=n-1
            while(j < k){
                sum = nums[i] + nums[j] + nums[k];
                if(sum < target){           // if i+j+k < target, any number between j and k can be regarded as k
                    ans += k-j;
                    j++;
                }else{
                    k--;
                }
            }
        }
        return ans;
    }
};