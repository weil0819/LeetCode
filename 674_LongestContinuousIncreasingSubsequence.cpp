class Solution {
public:
    /**
    * Idea: just compare the adjacent two elements
    * 
    */
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int output = 1, tmp = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > nums[i-1]){
                ++tmp;
                if(i == nums.size()-1){
                    output = max(output, tmp);
                }
            }else{
                output = max(output, tmp);
                tmp = 1;
            }
        }
        return output;
    }
};