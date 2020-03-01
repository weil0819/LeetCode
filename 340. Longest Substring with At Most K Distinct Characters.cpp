/*

340. Longest Substring with At Most K Distinct Characters
http://www.leetfree.com/problems/longest-substring-with-at-most-k-distinct-characters.html

Given a string, find the length of the longest substring T that contains at most k distinct characters.

For example, Given s = “eceba” and k = 2,

T is "ece" which its length is 3.

*/

class Solution {
public:
	/*

	使用hash表存放<字符，个数>
	遍历字符串将其加入到hash表中, 不同字符多于k个了, 就从左边开始删字符, 直到hash表不同字符长度等于k.
	此时字符串的长度就是当前字符和左边界的距离。

	*/
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> hash;		// <char, #char>
        int left = 0, Max = 0;				// left most index
        for(int i = 0; i < s.size(); i++)
        {
            hash[s[i]]++;
            while(hash.size()>k)
            {
                hash[s[left]]--;
                if(hash[s[left]]==0) hash.erase(s[left]);
                left++;
            }
            Max = max(Max, i-left+1);		// current substring is s[left: i]
        }
        return Max;
    }
};