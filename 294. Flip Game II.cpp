/*

294. Flip Game II
http://www.leetfree.com/problems/flip-game-ii.html


You are playing the following Flip Game with your friend: 
Given a string that contains only these two characters: + and -, 
you and your friend take turns to flip twoconsecutive "++" into "--". 
The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. 
The starting player can guarantee a win by flipping the middle "++" to become "+--+".

Follow up:
Derive your algorithm's runtime complexity.

*/

/*
判断第一个开始的人是否能确保赢得比赛
*/
class Solution {  
public:  
	/*
	枚举每一种情况，然后递归到下一层，看对手可不可以赢，如果对手有赢得情况那么就无法保证一定能赢。
	如果对手(第二个选手)无法赢，那么表明第一个选手一定能赢
	时间复杂度是指数。
	使用unordered_map<string, bool> hash记录枚举的字符串是否能让当前选手赢 
	*/
    bool canWin(string s) {  
        if(hash.count(s)) return hash[s];		// if s is visited, which indicates current will lost
        for(int i = 0; i < (int)s.size() -1; i++)
        {
            if(s.substr(i,2)!="++") continue;

            string str = s.substr(0,i)+"--"+s.substr(i+2);	// next string

            if(!canWin(str)) { 					// if next player cannot win with str
            	hash[str] = false ; 
            	return true; 
            }
            hash[str] = true;					// if next player can win with str
        }
        return false;
    }  
private:
	unordered_map<string, bool> hash;	// <string, win or lost of the second player>

};  

