class Solution {
public:
    /**
    * Idea: 1.use a unordered_map<int, int> to record the element and #element
    *       2.sort the array and scan it
    */
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pBegin = 0, pNew = 0, maxLen = 0, n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] - nums[pBegin] > 1){                
                pBegin = pNew;
            } 
            if(nums[i] != nums[i-1]){
                pNew = i;                
            }
            if(nums[i] - nums[pBegin] == 1){
                maxLen = max(maxLen, i-pBegin+1);
            }
        }

        return maxLen;
    }
};