/*

249. Group Shifted Strings -- Medium
http://www.leetfree.com/problems/group-shifted-strings.html

Given a string, we can "shift" each of its letter to its successive letter, 
for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, 
group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

*/

/*
已知一组字符串，将它们划分为相同的shifting 序列

*/

class Solution{
public:
	/*
	利用shift序列的特点：
	字符串相邻元素的差值相同，比如"abc"的差值就都是1，"az"的差值就是25
	这样，我们可以用字符串相邻元数据的差值和作为key，使用hashmap存放同一个shift序列的所有字符串

	a-z: 97-122
	A-Z: 65-90

	*/
	vector<vector<string> > groupStrings(vector<string>& strings) {
		unordered_map<string, vector<string> > hash;		// <key, pattern set>

        vector<vector<string>> res;
        
        for (int i = 0; i < strings.size(); ++i) {
            hash[calKey(strings[i])].push_back(strings[i]);
        }
        
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            sort(it->second.begin(), it->second.end());	// ouput in ascending order
            vector<string> tmp = it->second;
            res.push_back(tmp);
        }
        
        return res;

	}

private:
    string calKey(string input) {				// compute the sum of differences
        string key = "";
        for (int i = 0; i < input.length() - 1; ++i) {
        	// acef => a<c, gap=24 & c<e, gap=24 & e<f, gap=24 => key = "yyy"
            int gap = (input[i] > input[i+1]) ? (input[i] - input[i+1]) : (input[i] - input[i+1] + 26);
            char num = 'a' + gap;
            key += num;
        }
        return key;
    }

};