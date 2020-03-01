/*

243. Shortest Word Distance -- Easy
https://www.leetfree.com/problems/shortest-word-distance.html

Given a list of words and two words word1 and word2, 
return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.

*/

/*
已知一组words和两个词word1和word2
求两个词之间的距离

顺序遍历list，使用两个变量p和q记录word1和word2的索引
然后计算差值

*/

class Solution {
public: 
    int shortestDistance(vector<string>& words, string word1, string word2) {
    	int n = words.size();
    	int p = -1, q = -1, res = INT_MAX;
    	for(int i = 0; i < n; i++){
    		if(words[i] == word1){
    			p = i;
    		}else if(words[i] == word2){
    			q = i;
    		}
    		if(p != -1 && q != -1){
    			res = min(abs(p-q), res);
    		}
    	}
    	return res;
    }
};



