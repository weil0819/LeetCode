//===========================================================================================
// 1. Two Sum
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// Example:
// Given nums = [2, 7, 11, 15], target = 9,

// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].
//===========================================================================================

class Solution {
public:
    /**
    * Idea: 1.straightforward method to sum any two adjacent numbers, time complexity is O(n^2)
    * 2.use an unordered_map<int, int> to record the number and its index
    * 
    */
    // Method-I
    /*    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        int i, j;
        for(i = 0; i < nums.size()-1; i++){
            for(j = i+1; j < nums.size(); j++){
                if(nums[i] +nums[j] == target){
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
    }
    */
    
    // Method-II
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> help;
        vector<int> output;
        for(int i = 0; i < nums.size(); i++){
            int remainV = target - nums[i];
            if(help.find(remainV) != help.end()){
                output.push_back(i);
                output.push_back(help.find(remainV)->second);
                return output;
            }else{
                help.insert(make_pair(nums[i], i));
            }
        }
    }
};