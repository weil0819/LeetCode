//===========================================================================================
// 498. Diagonal Traverse

// Given a matrix of M x N elements (M rows, N columns), 
// return all elements of the matrix in diagonal order as shown in the below image.

// Example:
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output:  [1,2,4,7,5,3,6,8,9]
// Explanation:

// Note:
// The total number of elements of the given matrix will not exceed 10,000.
//===========================================================================================


class Solution {
public:
    /**
    * Idea: For aboved example, (0,0)-->(0,1)-->(1,0)-->(2,0)->(1,1)->(0,2)-->(1,2)-->(2,1)->(2,2)
    * There are two directions: (x, y)-->(x+1, y-1) or (x-1, y+1)
    * There are 4 cases under which we need to change the direction:
    * case1: If out of bottom border (row >= M) then row = M - 1; col += 2; change walk direction
    * case2: if out of right border (col >= N) then col = N - 1; row += 2; change walk direction.
    * case3: if out of top border (row < 0) then row = 0; change walk direction.
    * case4: if out of left border (col < 0) then col = 0; change walk direction.
    * 
    */
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0){
            return res;
        }
        int M = matrix.size(), N = matrix[0].size();        
        res.reserve(M*N);
        
        int row = 0, col = 0, d = 1;
        for(int i = 0; i < M*N; i++){
            res.push_back(matrix[row][col]);
            row -= d;
            col += d;

            if(row >= M){
                row = M-1;
                col += 2;
                d = -d;
            }
            if(col >= N){
                col = N-1;
                row += 2;
                d = -d;
            }
            if(row < 0){
                row = 0;
                d = -d;
            }
            if(col < 0){
                col = 0;
                d = -d;
            }
        }

        return res;
    }
};