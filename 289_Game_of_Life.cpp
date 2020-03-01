//===========================================================================================
// 289. Game of Life

// According to the Wikipedia's article: "The Game of Life, also known simply as Life, 
// is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). 
// Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) 
// using the following four rules (taken from the above Wikipedia article):

// Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population..
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// Write a function to compute the next state (after one update) of the board given its current state.

// Follow up: 
// Could you solve it in-place? Remember that the board needs to be updated at the same time: 
// You cannot update some cells first and then use their updated values to update other cells.
// In this question, we represent the board using a 2D array. In principle, 
// the board is infinite, which would cause problems when the active area encroaches the border of the array. 
// How would you address these problems?
//===========================================================================================

class Solution {
public:
	/**
	* Idea: we need to create a function which return the number of live neighbors
	* the board needs to be updated at the same time
	* thus, we should flag a new val for changed position
	* 
	*/
    void gameOfLife(vector<vector<int> >& board) {
        int m = board.size(), n = 0;
        if(m > 0){
            n = board[0].size();
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int num = getLiveNeigh(board, i, j);
                if(board[i][j] == 1 && num < 2){
                    board[i][j] = 2;                    // flag=2 means dead next round -->0
                }else if(board[i][j] == 1 && num > 3){
                    board[i][j] = 2;
                }else if(board[i][j] == 0 && num == 3){
                    board[i][j] = -2;                   // flag=-2 means live next round -->1
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == -2){
                    board[i][j] = 1;
                }else if(board[i][j] == 2){
                	board[i][j] = 0;
                }
            }
        }
    }

    int getLiveNeigh(vector<vector<int> >& board, int i, int j){
        int res = 0, m = board.size(), n = 0;
        if(m > 0){
            n = board[0].size();
        }
        for(int x = max(i-1,0); x <= min(i+1, m-1); x++){
            for(int y = max(j-1,0); y <= min(j+1, n-1); y++){
                if(board[x][y] > 0){
                    res++;
                }
            }
        }
        if(board[i][j] > 0){
            res = res -1;
        }
        return res;
    }
};