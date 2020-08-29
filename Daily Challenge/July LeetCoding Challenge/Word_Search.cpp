/*
Word Search

@date: July 21, 2020

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/

class Solution {
public:
    // Scan each grid, if there is a word starting with that
    bool exist(vector<vector<char>>& board, string word) {
        int N = board.size();
        if(N == 0 || word.size() == 0) return false;
        int M = board[0].size();
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(board[i][j] == word[0]) {
                    if(BFSUtil(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
private:    
    bool BFSUtil(vector<vector<char>>& board, string word, int i, int j, int idx) {
        if(idx == word.size()) return true;
        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || board[i][j] == '\0') return false;
        if(board[i][j] != word[idx]) return false;
        char tmp = board[i][j];
        board[i][j] = '\0';     // has been visited
        // any 4 directions has a word
        bool isExist = BFSUtil(board, word, i+1, j, idx+1) || BFSUtil(board, word, i-1, j, idx+1) || 
            BFSUtil(board, word, i, j+1, idx+1) || BFSUtil(board, word, i, j-1, idx+1);
        board[i][j] = tmp;      // recover as unvisited
        return isExist;
    }
    
};
