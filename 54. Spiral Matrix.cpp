/*

54. Spiral Matrix
https://leetcode.com/problems/spiral-matrix/description/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

class Solution {
public:
    /**
    * Idea: this is a Matrix problem
    * (i=0) => (j=n-1) => (i=m-1) => (j=0)
    * (i=1) => (j=n-2) => (i=m-2) => (j=1)
    * (i=2) => (j=n-3) => (i=m-3) => (j=2)
    * we can divide this task into 4 loops
    * 
    * time complexity: O(N*M)
    * space complexity: O(1) except the return value
    * 
    */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> res;
        if(m == 0){
            return res;
        }        
        int n = matrix[0].size();
        
        int rowBegin = 0, rowEnd = m-1;
        int colBegin = 0, colEnd = n-1;
        while(rowBegin <= rowEnd && colBegin <= colEnd){
            // scan row 
            for(int j = colBegin; j <= colEnd; j++){
                res.push_back(matrix[rowBegin][j]);
            }
            rowBegin++;
            
            // scan col
            for(int i = rowBegin; i <= rowEnd; i++){
                res.push_back(matrix[i][colEnd]);               
            }
            colEnd--;
            
            // reverse scan row 
            if(rowBegin <= rowEnd){     // we need to make sure that rowEnd is valid
                for(int j = colEnd; j >= colBegin; j--){
                    res.push_back(matrix[rowEnd][j]);
                }                
            }
            rowEnd--;
            
            // reverse scan col
            if(colBegin <= colEnd){    // we need to make sure that colBegin is valid
                for(int i = rowEnd; i >= rowBegin; i--){
                    res.push_back(matrix[i][colBegin]);
                }                
            }
            colBegin++;            
        }
        return res;
    }
};