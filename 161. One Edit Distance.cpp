/*
161. One Edit Distance -- Medium
https://www.leetfree.com/problems/one-edit-distance.html
http://www.cnblogs.com/grandyang/p/5184698.html

Given two strings S and T, determine if they are both one edit distance apart.

*/

// Approach #1: 
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size();
        int diff = n-m;

        if(abs(diff) > 1) return false;				// Case-I: more than one different char
        else if(diff == 1) {						// Case-II: only one different char
        	for(int i = 0; i < m; i++) {
        		if(s[i] != t[i]) return s.substr(i+1) == t.substr(i);
        	}
        }else if(diff == -1) {
        	for(int i = 0; i < n; i++) {
        		if(s[i] != t[i]) return t.substr(i+1) == s.substr(i);
        	}
        }else{										// Case-III: same length
        	int cnt = 0;
        	for(int i = 0; i < n; i++) {
        		if(s[i] != t[i]) ++cnt;
        	}   
        	return cnt == 1;     	
        }        
    }
};

// Approach #2: 
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
    	// scan each char in shorter string
        for (int i = 0; i < min(s.size(), t.size()); ++i) {
            if (s[i] != t[i]) {
                if (s.size() == t.size()) return s.substr(i + 1) == t.substr(i + 1);
                else if (s.size() < t.size()) return s.substr(i) == t.substr(i + 1);
                else return s.substr(i + 1) == t.substr(i);
            }
        }
        // compare the length of these two strings
        return abs((int)s.size() - (int)t.size()) == 1;
    }
};
