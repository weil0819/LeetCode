/*

348. Design Tic-Tac-Toe -- Medium
http://www.leetfree.com/problems/design-tic-tac-toe.html

Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|

Follow up:
Could you do better than O(n2) per move() operation?

*/


/*

每次移动，先判断横竖两行，如果能够排满当前player，那么就结束
如果(row, col)刚好在对角线上，那么判断对角线是否排满当前player

使用rows和cols分别存放每行/每列的累加和，使用diagnal和antiDiagnal分别表示对角线和反对角线的值
我们认为如果是player-1的话，那么就在每行和每列+1，如果是player-2就在每行和每列-1
如果rows，cols，diagnal或antiDiagnal的累加和的值刚好是n，那么就认为是有一方win

*/
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n):rows(vector<int>(n, 0)), cols(vector<int>(n, 0)) {
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int flag = (player==1?1:-1), n = rows.size();
        rows[row] += flag, cols[col]+=flag;

        if(row==col) antiDiagnal += flag;
        if(row+col+1 == n) diagnal += flag;

        if(abs(rows[row])==n || abs(cols[col])==n 
          ||abs(diagnal)==n || abs(antiDiagnal)==n) 
            return player;
        return 0;
    }
private:
    vector<int> rows, cols;			// define row and col
    int diagnal=0, antiDiagnal=0;
};
 
/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */