//===========================================================================================
// 419. Battleships in a Board

// Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, 
// empty slots are represented with '.'s. You may assume the following rules:

// You receive a valid board, made of only battleships or empty slots.
// Battleships can only be placed horizontally or vertically. In other words, 
// they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
// At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.
// Example:
// X..X
// ...X
// ...X
// In the above board there are 2 battleships.
// Invalid Example:
// ...X
// XXXX
// ...X
// This is an invalid board that you will not receive - as battleships will always have a cell separating between them.
// Follow up:
// Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
//===========================================================================================
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	/**
	* Idea: For a element board[i][j], if board[i-1][j] and board[i][j-1] are both not 'X'
	* Attention: the test case2 is not correct
	*
	*/
    int countBattleships(vector<vector<char> >& board) {
    	int n = board.size(), m = board[0].size();
    	int count = 0;
        for(int i = 0; i < n; i++){
        	for(int j = 0; j < m; j++){
        		if(board[i][j] == 'X'){
        			if(i > 0 && board[i-1][j] == 'X'){
        				continue ;
        			}
        			if(j > 0 && board[i][j-1] == 'X'){
        				continue ;
        			}
        			++count;
        		}
        	}
        }
        return count;
    }
};

int main(){
	Solution sn;
	char a[] = {'.', '.', '.', 'X'};
	char b[] = {'X', 'X', 'X', 'X'};
	char c[] = {'.', '.', '.', 'X'};
	vector<char> aa(a, a+4);
	vector<char> bb(b, b+4);
	vector<char> cc(c, c+4);
	vector<vector<char> > board;
	board.push_back(aa);
	board.push_back(bb);
	board.push_back(cc);
	cout<<sn.countBattleships(board)<<endl;
	return 0;
}