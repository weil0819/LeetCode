/*
456. 132 Pattern
https://leetcode.com/problems/132-pattern/description/

*/

class Solution {
public:
    // Method-I: O(n^2) and O(1)
    /*
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return false;
        int ai = INT_MAX;
        for(int j = 0; j < n-1; j++){               // O(n^2)
            ai = min(ai, nums[j]);
            for(int k = j+1; k < n; k++){
                if(nums[k] < nums[j] && ai < nums[k]) return true;
            }
        }
        return false;
    }*/
    
    // Method-II: O(n) and O(n)
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return false;
        vector<int> ai(n);
        ai[0] = nums[0];
        for(int j = 1; j < n; j++){
            ai[j] = min(ai[j-1], nums[j]);
        }
        stack<int> S;                       // store ak
        for(int j = n-1; j >= 0; j--){
            int aj = nums[j];
            if(aj > ai[j]){                // ai < aj, where ai[j] is the minimum value in array which is smaller than aj                
                while(!S.empty() && S.top() <= ai[j]){  // when ak <= ai, pop out until ai < ak
                    S.pop();
                }               
                if(!S.empty() && S.top() < aj){         // ak < aj
                    return true;
                }
                S.push(aj);
            }
        }
        return false;
    }
};

