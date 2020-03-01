/*

31. Next Permutation
https://leetcode.com/problems/next-permutation/description/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/

class Solution {
private:
    void reverseArray(vector<int>& nums, int begin, int end){
        int i = begin, j = end;
        while(i < j){
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
    }
    
public:
    /**
    * Idea: this is a Array problem
    * By observation, if the permutation is in descending order, it is the highest one
    * if not, we should find the first number nums[i] that nums[i] < nums[i+1], from end to begin
    * eg, 4537621-->4561237, index = 2
    * we should swap 3 with 6, so we need to traverse from end to begin to find the first i where nums[j] > nums[index]
    * and then swap nums[index] and nums[j], sort [index+1, n-1]
    * 4537621 --> 4567321 --> 4561237
    * 
    * time complexity: O(N), where N is the size of nums
    * space complexity: O(1)
    * 
    */
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return ;
        }
        int index = -1;
        for(int i = n-2; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        if(index == -1){
            reverseArray(nums, 0, n-1);
            return ;
        }
        int j = -1;
        for(j = n-1; j > index; j--){
            if(nums[j] > nums[index]){
                break;
            }
        }
        int tmp = nums[j];
        nums[j] = nums[index];
        nums[index] = tmp;
        
        reverseArray(nums, index+1, n-1);
    }
};

