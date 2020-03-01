class Solution {
public:
    /**
    * Idea: for a sorted array, we first consider the binary search 
    * 
    */
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                low = mid+1;
                if(low > high){
                    return low;
                }
            }else{
                high = mid-1;
                if(high < low){
                    return low;
                }
            }
        }
        
    }
};