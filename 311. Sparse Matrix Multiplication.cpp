/*

311. Sparse Matrix Multiplication -- Medium
http://www.leetfree.com/problems/sparse-matrix-multiplication.html

Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |

*/

class Solution {
public:
	/*
	在遍历A[i][k]的时候，先去查看 A[i][k]是否为0，如果不是我们才去拿B当前col的每一位去计算
	*/
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(), n = A[0].size(), p = B[0].size();
        vector<vector<int>> ans(m, vector<int>(p, 0));
        for(int i = 0; i < m; i++)
        {
            for(int k = 0; k < n; k++)
            {
                if(A[i][k] == 0) continue;
                for(int j = 0; j < p; j++) ans[i][j] += A[i][k] * B[k][j];
            }
        }
        return ans;        
    }
    /*

    */
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    	int m = A.size(), n = A[0].size(), p = B.size(), q = B[0].size();
    	vector<vector<int>> ans(m, vector<int>(q));
    	if(m == 0 || n == 0 || n != p) return ans;
    	vector<pair<int, vector<int> > > rowInA, colInB;	// store non-zero rows in A and cols in B

    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(A[i][j] != 0){
    				rowInA.push_back(make_pair(i, A[i]));
    				break;
    			}
    		}
    	}

        for(int j = 0; j < q; j++) {
            for(int i = 0; i < p; i++) {
                if(B[i][j] != 0) {
                    vector<int> tmp(p);
                    for(int k = 0; k < p; k++) {
                        tmp[k] = B[k][j];
                    }
                    colInB.push_back(make_pair(j, tmp));
                    break;
                }
            }
        }

        for(int i = 0; i < rowInA.size(); i++) {
            for(int j = 0; j < colInB.size(); j++) {
                for(int k = 0; k < n; k++) {
                    ans[i][j] += rowInA[i][k] * colInB[j][k];
                }
            }
        }  

        return ans;              
    }

};