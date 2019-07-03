//===========================================================================================
// 692. Top K Frequent Words
// Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest. 
// If two words have the same frequency, then the word with the lower alphabetical order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.
//===========================================================================================
class MyCompare{
public:
	bool operator() (const pair<string, int>& lhs, const pair<string, int>&rhs) const{
		if(lhs.second > rhs.second || (lhs.second == rhs.second && lhs.first < rhs.first)){
			return true;
		}else{
			return false;
		}
	}
};
class Solution {
public:
    /**
    * Idea: we can use a unordered_map<string, int> to record the <word, frequent>
    * and we also need to use priority_queue 
    * Attention: in priority_queue, the top element with the smallest frequent
    *
    */
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mapHelper;
        for(int i = 0; i < words.size(); i++){
            ++mapHelper[words[i]];
        }
        priority_queue<pair<string, int>, vector<pair<string, int> >, MyCompare> priHelper;

        for(unordered_map<string, int>::iterator it = mapHelper.begin(); it != mapHelper.end(); ++it){
            priHelper.push(make_pair(it->first, it->second));
            if(priHelper.size() > k){
                priHelper.pop();
            }
        }
        stack<string> tmp;
        for(int i = 0; i < k; i++){
            tmp.push(priHelper.top().first);
            priHelper.pop();
        }
        vector<string> res;
        while(!tmp.empty()){
            res.push_back(tmp.top());
            tmp.pop();
        }
        return res;
    }
};

