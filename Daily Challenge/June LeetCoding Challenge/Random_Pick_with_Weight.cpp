/*
Random Pick with Weight

@date: June 5, 2020

Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.

Note:

1 <= w.length <= 10000
1 <= w[i] <= 10^5
pickIndex will be called at most 10000 times.
Example 1:

Input: 
["Solution","pickIndex"]
[[[1]],[]]
Output: [null,0]
Example 2:

Input: 
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
Output: [null,0,1,1,1,0]
Explanation of Input Syntax:

The input is two lists: the subroutines called and their arguments. Solution's constructor has one argument, the array w. pickIndex has no arguments. Arguments are always wrapped with a list, even if there aren't any.

*/

class Solution {
private:
    vector<int> vec;
    
public:
    Solution(vector<int>& w) {
        for(int i = 0; i < w.size(); i++) {
            vec.push_back(vec.empty() ? w[i] : w[i]+vec.back());
        }
    }
    
    // [1,3] means P(0)=1/4, P(1)=3/4
    // accumulate sum = [1,4], get a random number in range[1,4] 
    // if it is 1, pick index=0, else pick index=1
    int pickIndex() {
        int n = vec.back();
        int r = rand() % n + 1;     // [1, n]
        int low = 0, high = vec.size()-1;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(vec[mid] < r) low = mid + 1;
            else if(vec[mid] > r) high = mid - 1;
            else return mid;
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
 
