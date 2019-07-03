class Solution {
public:
    /**
    * Idea: n-1 elements increase 1 == one element decreases 1
    * Finally, all element become the minimum element
    * So, each element i has (i-min) moves
    */
    int minMoves(vector<int>& nums) {
        int minE = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < minE){
                minE = nums[i];
            }
        }
        int output = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > minE){
                output += nums[i]-minE;
            }
        }
        return output;
    }
};