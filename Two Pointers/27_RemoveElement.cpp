class Solution {
public:
    /**
    * Idea: one point p which points to 0 at begining
    * when it comes to a element different from val, p++
    * 
    */
    int removeElement(vector<int>& nums, int val) {
        int p = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[p] = nums[i];
                ++p;
            }
        }
        return p;
    }
};