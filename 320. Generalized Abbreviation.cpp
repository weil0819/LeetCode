/*

320. Generalized Abbreviation -- Medium
http://www.leetfree.com/problems/generalized-abbreviation.html

Write a function to generate the generalized abbreviations of a word.

Example:
Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

*/

class Solution{
public:
	/*
	用len(word)个二进制表示word，凡是0的地方都是原来的字母，
	单独的1还是1，如果是若干个1连在一起的话，就要求出1的个数，用这个数字来替换对应的字母
	*/
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        for (int i = 0; i < pow(2, word.size()); ++i) {
            string out = "";			// abbreviation
            int cnt = 0;				// count number of 1
            for (int j = 0; j < word.size(); ++j) {
                if ((i >> j) & 1) ++cnt;
                else {
                    if (cnt != 0) {
                        out += to_string(cnt);
                        cnt = 0;
                    }
                    out += word[j];		// if 0, directly use the char
                }
            }
            if (cnt > 0) out += to_string(cnt);
            res.push_back(out);
        }
        return res;    	
    }	

    /*
	backtrack算法：
	用pos记录遍历word的位置
	用cnt记录缩写字符数
	用out记录缩写的word

    */
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        backtrack(word, 0, 0, "", res);
        return res;
    }
    void backtrack(string word, int pos, int cnt, string out, vector<string> &res) {
        if (pos == word.size()) {
            if (cnt > 0) out += to_string(cnt);
            res.push_back(out);
        } else {
        	// case 1: abbreviate the next character        	
            backtrack(word, pos + 1, cnt + 1, out, res);
            	
            // case 2: keep the next character	
            backtrack(word, pos + 1, 0, out + (cnt > 0 ? to_string(cnt) : "") + word[pos], res);
        }
    }

};