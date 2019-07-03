class Solution {
public:
    /**
    * Idea: dynamic programming problem
    * The last action may be 1 step or 2 steps, we know that the stair has n steps
    * we use med[i] to represent the #method that can reach the i-th steps, thus, med[i] = med[i-1] + med[i-2]
    * 
    */
    int climbStairs(int n) {
        vector<int> med(n+1, 0);
        med[0] = 0;
        med[1] = 1;
        med[2] = 2;
        for(int i = 3; i <= n; i++){
            med[i] = med[i-1] + med[i-2];
        }
        return med[n];
    }
};