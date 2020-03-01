//==========================================================================================
// 526. Beautiful Arrangement

// Suppose you have N integers from 1 to N. We define a beautiful arrangement as an array that is constructed by these N numbers successfully if one of the following is true for the ith position (1 <= i <= N) in this array:

// The number at the ith position is divisible by i.
// i is divisible by the number at the ith position.
// Now given N, how many beautiful arrangements can you construct?

// Example 1:
// Input: 2
// Output: 2
// Explanation: 

// The first beautiful arrangement is [1, 2]:

// Number at the 1st position (i=1) is 1, and 1 is divisible by i (i=1).

// Number at the 2nd position (i=2) is 2, and 2 is divisible by i (i=2).

// The second beautiful arrangement is [2, 1]:

// Number at the 1st position (i=1) is 2, and 2 is divisible by i (i=1).

// Number at the 2nd position (i=2) is 1, and i (i=2) is divisible by 1.
// Note:
// N is a positive integer and will not exceed 15.
//==========================================================================================
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    /**
     * Idea: backtracking method
     *
     */
    int countArrangement(int N) {
        vector<int> vec;
        for(int i = 0; i <= N; i++){
            vec.push_back(i);
        }
        int count = 0;
        compute(vec, N, count);
        return count;
    }

    void compute(vector<int>& vec, int n, int& count){
        if(n == 0){
            count++;
            return ;
        }
        for(int i = 1; i <= n; i++){
            if(vec[i]%n == 0 || n%vec[i] == 0){
                swap(vec[i], vec[n]);
                compute(vec, n-1, count);
                swap(vec[n], vec[i]);
            }
        }
    }
};

int main(){
    Solution sn;
    int N = 2;
    cout<<sn.countArrangement(N)<<endl;
    return 0;
}
