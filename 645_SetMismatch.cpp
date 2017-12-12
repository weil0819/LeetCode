class Solution {
public:
    /**
    * Idea: if nums[i] > 0, we set nums[nums[i]-1] = nums[nums[i]-1]
    * if nums[nums[i]-1] itself is negative, nums[i] must be duplicated number
    * 
    */
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> output;
        for(int i = 0; i < nums.size(); i++){
            int pos = abs(nums[i]) - 1;
            if(nums[pos] < 0){
                output.push_back(abs(nums[i]));
            }else{
                nums[pos] = -nums[pos];
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                output.push_back(i+1);
            }
        }
        return output;
    }
};