//===========================================================================================
// 59. Spiral Matrix II

// Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

// For example,
// Given n = 3,

// You should return the following matrix:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]
//===========================================================================================

class Solution {
public:
	/**
	* Idea: there are four kinds of movements:
	* case1: horizontal move from left to right
	* case2: vertical move from up to down
	* case3: horizontal move from right to left
	* case4: vertical move from down to up
	* 
	*/
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > res(n, vector<int>(n));
        if(n == 0){
        	return res;
        }
        int cnt = 1, i = 0, j = 0;
        while(cnt <= n*n){
        	//case1:
        	while(j <= n-1){
        		res[i][j] = cnt;
        		++cnt;
        	}
        	i = i+1;
        	//case2: 
        	while(){

        	}

        	//case3:
        	while(){

        	}


        }

        return res;
    }
};