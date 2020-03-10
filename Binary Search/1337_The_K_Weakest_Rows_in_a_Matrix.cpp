/*
1337. The K Weakest Rows in a Matrix -- Easy
https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

@date: Tue 10 Mar. 2020

Given a m * n matrix mat of ones (representing soldiers) and zeros (representing civilians), return the indexes of the k weakest rows in the matrix ordered from the weakest to the strongest.

A row i is weaker than row j, if the number of soldiers in row i is less than the number of soldiers in row j, or they have the same number of soldiers but i is less than j. Soldiers are always stand in the frontier of a row, that is, always ones may appear first and then zeros.

 
Example 1:

Input: mat = 
[[1,1,0,0,0],
 [1,1,1,1,0],
 [1,0,0,0,0],
 [1,1,0,0,0],
 [1,1,1,1,1]], 
k = 3
Output: [2,0,3]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 2 
row 1 -> 4 
row 2 -> 1 
row 3 -> 2 
row 4 -> 5 
Rows ordered from the weakest to the strongest are [2,0,3,1,4]
Example 2:

Input: mat = 
[[1,0,0,0],
 [1,1,1,1],
 [1,0,0,0],
 [1,0,0,0]], 
k = 2
Output: [0,2]
Explanation: 
The number of soldiers for each row is: 
row 0 -> 1 
row 1 -> 4 
row 2 -> 1 
row 3 -> 1 
Rows ordered from the weakest to the strongest are [0,2,3,1]
 

Constraints:

m == mat.length
n == mat[i].length
2 <= n, m <= 100
1 <= k <= m
matrix[i][j] is either 0 or 1.

*/

bool myComp(pair<int, int>& A, pair<int, int>& B) {
    if(A.first < B.first) return true;
    else if(A.first == B.first) return A.second < B.second;
    else return false;
}
class Solution {
public:
    // Use binary search to calculate how many soldier in each row
    // Use a vector<pair<int,int>> to record <#soldier, rowID>
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int N = mat.size();
        if(N == 0 || k == 0) return vector<int>();
        
        vector<int> res(k);
        vector<pair<int, int> > help(N);
        for(int i = 0; i < N; i++) {
            int soldiers = getSoldiers(mat[i]);
            help[i] = make_pair(soldiers, i);
        }
        sort(help.begin(), help.end(), myComp);
        for(int i = 0; i < k; i++) {
            res[i] = help[i].second;
        }
        return res;
    }
    
    int getSoldiers(vector<int>& row) {
        int l = 0, r = row.size()-1;
        while(l <= r) {
            int m = l + (r-l)/2;
            if(row[m] == 0) {
                r = m - 1;
            }else {
                l = m + 1;
            }
        }
        return l;
    }
};


