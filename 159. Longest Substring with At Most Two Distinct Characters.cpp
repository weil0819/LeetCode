/*

159. Longest Substring with At Most Two Distinct Characters -- Hard
http://www.leetfree.com/problems/longest-substring-with-at-most-two-distinct-characters.html


Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

For example, Given s = “eceba”,

T is “ece” which its length is 3.

*/

class Solution {
public:
	/*
	类似：340. Longest Substring with At Most K Distinct Characters
	使用hash表存放<字符，个数>
	遍历字符串将其加入到hash表中, 不同字符多于2个了, 就从左边开始删字符, 直到hash表不同字符长度等于2.
	此时字符串的长度就是当前字符和左边界的距离。
	*/
    int lengthOfLongestSubstringTwoDistinct(string s) {
    	unordered_map<char, int> hash;
    	int n = s.size();
    	int left = 0, Max = 0;
    	for(int i = 0; i < n; i++){
    		hash[s[i]]++;
    		while(hash.size() > 2){
    			hash[s[left]]--;			// remove the left-most char
    			if(hash[s[left]] == 0) hash.erase(s[left]);
    			left++;
    		}
    		Max = max(Max, i-left+1);
    	}
    	return Max;
    }
};