class Solution {
public:
    /**
    * Idea: since the array is sorted, we can consider using two points which point to head and tail
    * If head+tail < target, head++; If head+tail > target, tail--
    */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int low = 0, high = n-1;
        while(numbers[low]+numbers[high] != target){
            if(numbers[low]+numbers[high] < target){
                low++;
            }else{
                high--;
            }            
        }
        vector<int> output;
        output.push_back(low+1);
        output.push_back(high+1);
        return output;
    }
};