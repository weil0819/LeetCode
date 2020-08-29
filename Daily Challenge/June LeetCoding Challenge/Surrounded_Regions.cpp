/*
Surrounded Regions

@date: June 17, 2020

Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

*/

class Solution {
public:
    // Recursive + BFS
    // Any border 'O' and its neighbors should be converted into 'Y'
    // the remaining 'O' should be changed to 'X'
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) return ;
        int col = board[0].size();
        
        // check columns
        for(int i = 0; i < row; i++) {
            BFSUtil(board, i, 0, row, col);                     // first column
            if(col > 1) BFSUtil(board, i, col-1, row, col);     // last column  
        }
        
        // check rows
        for(int j = 0; j < col; j++) {
            BFSUtil(board, 0, j, row, col);                     // first row
            if(row > 1) BFSUtil(board, row-1, j, row, col);     // last row
        }
        
        // start changing
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == 'Y') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }        
        
    }
private:
    void BFSUtil(vector<vector<char>>& board, int i, int j, int row, int col) {
        if(board[i][j] == 'O'){
            board[i][j] = 'Y';
            if(i > 1) BFSUtil(board, i-1, j, row, col);
            if(j > 1) BFSUtil(board, i, j-1, row, col);
            if(i+1 < row) BFSUtil(board, i+1, j, row, col);
            if(j+1 < col) BFSUtil(board, i, j+1, row, col);
        }
    }
};