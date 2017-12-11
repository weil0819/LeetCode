class Solution {
public:
    /**
    * Idea: sort the array and then scan it
    * This approach has extra space cost used for sorting
    */
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
};