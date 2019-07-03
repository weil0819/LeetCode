class Solution {
public:
    /**
    * Idea: two points p and q, which point to 0 at begining
    * traverse each element if it is non-zero, p points it and q++
    * that means q always points to the first zero element
    * 
    */
    void moveZeroes(vector<int>& nums) {
        int p = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                if(i != p){
                    swap(nums[i], nums[p]);
                }
                ++p;
            }
        }
    }
};