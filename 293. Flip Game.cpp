/*

293. Flip Game -- Easy
http://www.leetfree.com/problems/flip-game.html

You are playing the following Flip Game with your friend: 
Given a string that contains only these two characters: + and -, 
you and your friend take turns to flip two consecutive "++" into "--". 
The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.

For example, given s = "++++", after one move, it may become one of the following states:

[
  "--++",
  "+--+",
  "++--"
]

If there is no valid move, return an empty list [].

*/
/*
求一次有效移动之后，字符串的所有可能状态
*/
class Solution {
public:
	/*
	顺序遍历字符串，如果遇到连续的两个"++"，那么就将这两个"++"换成"--"
	*/
    vector<string> generatePossibleNextMoves(string s) {
    	vector<string> res;
    	int n = s.size();
    	for(int i = 0; i < n-1; i++){
    		if(s[i] == '+' && s[i+1] == '+'){
    			res.push_back(s.substr(0,i) + "--"+s.substr(i+2));
    		}
    	}
    	return res;
    }
};