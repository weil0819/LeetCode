class Solution {
public:
    /**
    * Idea: sort the array and then compute the product of the last three numbers
    * Attention: there will exist negative integers, such as [-4,-3,-2,-1,60]
    * here, we should compute the product of the first two and the last one
    */
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if(n < 3){
            return 0;
        }
        sort(nums.begin(), nums.end());        
        int x = nums[n-1], y = nums[n-2], z = nums[n-3];
        int yy = nums[0], zz = nums[1];
        return x*y*z > x*yy*zz ? x*y*z : x*yy*zz;
    }
};