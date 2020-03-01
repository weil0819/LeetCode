/*

266. Palindrome Permutation -- Easy
http://www.leetfree.com/problems/palindrome-permutation.html

Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.

*/

/*
问题：判断一个字符串的排列是否是回文的


如果所有的字符都出现偶数次，那么肯定可以回文
如果只有一个字符出现奇数次，肯定也可以回文
用一个hash表来记录每个字符的个数，最后再统计一下奇数字符的数目
*/

class Solution{
public:
	bool canPermutePalindrome(String s){
		unordered_map<int, int> UM;
		for(int i = 0; i < s.size(); i++){
			UM[s[i]]++;
		}
		int cnt = 0;
		for(auto p: UM){
			if(p.second % 2) cnt++;		// count how many chars appears odd times
		}
		return cnt <= 1;				// if cnt > 1, non-palindrome
	}
		
};

