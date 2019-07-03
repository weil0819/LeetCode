//===========================================================================================
// 688. Knight Probability in Chessboard

// On an NxN chessboard, a knight starts at the r-th row and c-th column and attempts to make exactly K moves. 
// The rows and columns are 0 indexed, so the top-left square is (0, 0), and the bottom-right square is (N-1, N-1).

// A chess knight has 8 possible moves it can make, as illustrated below. 
// Each move is two squares in a cardinal direction, then one square in an orthogonal direction.
// Each time the knight is to move, it chooses one of eight possible moves uniformly at random 
// (even if the piece would go off the chessboard) and moves there.

// The knight continues moving until it has made exactly K moves or has moved off the chessboard. 
// Return the probability that the knight remains on the board after it has stopped moving.

// Example:
// Input: 3, 2, 0, 0
// Output: 0.0625
// Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
// From each of those positions, there are also two moves that will keep the knight on the board.
// The total probability the knight stays on the board is 0.0625.
// Note:
// N will be between 1 and 25.
// K will be between 0 and 100.
// The knight always initially starts on the board.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: this is a DP problem
	* Let f[r][c][steps] be the probability of being on square (r, c) after steps steps.
	* Based on how a knight moves, we have the following recursion:
	* f[r][c][steps]=∑​_{dr,dc​​}f[r+dr][c+dc][steps−1]/8.0
	* where the sum is taken over the eight (dr, dc)(dr,dc) pairs 
	* (2, 1),(2, -1),(-2, 1),(-2, -1),(1, 2),(1, -2),(-1, 2),(-1, -2)
	* 
	*/
    double knightProbability(int N, int K, int r, int c) {
    	vector<pair<int, int> > helper;
    	helper.push_back(make_pair(2,1));
    	helper.push_back(make_pair(2,-1));
    	helper.push_back(make_pair(-2,1));
		helper.push_back(make_pair(-2,-1));
		helper.push_back(make_pair(1,2));
		helper.push_back(make_pair(1,-2));
		helper.push_back(make_pair(-1,2));
		helper.push_back(make_pair(-1,-2));
        vector<vector<vector<double> > > dp(N, vector<vector<double> >(N, vector<double>(K+1)));
        dp[r][c][0] = 1;
        for(int step = 1; step <= K; step++){
        	for(int i = 0; i < N; i++){
        		for(int j = 0; j < N; j++){
        			for(int move = 0; move < 8; move++){
        				int x = helper[move].first + i;
        				int y = helper[move].second + j;
        				if (x < 0 || x >= N || y < 0 || y >= N) continue;
        				dp[i][j][step] += dp[x][y][step-1]/8.0; 
        			}
        		}
        	}
        }
        double res = 0.0;
        for(int i = 0; i < N; i++){
        	for(int j = 0; j < N; j++){
        		res += dp[i][j][K];
        	}
        }
        return res;
    }
};
