/*
854. K-Similar Strings
https://leetcode.com/contest/weekly-contest-89/problems/k-similar-strings/

Strings A and B are K-similar (for some non-negative integer K) 
if we can swap the positions of two letters in A exactly K times so that the resulting string equals B.

Given two anagrams A and B, return the smallest K for which A and B are K-similar.

Example 1:

Input: A = "ab", B = "ba"
Output: 1
Example 2:

Input: A = "abc", B = "bca"
Output: 2
Example 3:

Input: A = "abac", B = "baca"
Output: 2
Example 4:

Input: A = "aabc", B = "abca"
Output: 2
Note:

1 <= A.length == B.length <= 20
A and B contain only lowercase letters from the set {'a', 'b', 'c', 'd', 'e', 'f'}

*/

class Solution {
private:
    string swap(string& str, int i, int j){
        string res = str;
        char tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
        return res;
    }
    
public:
    int kSimilarity(string A, string B) {
        if(A == B) return 0;
        int ans = 0;
        queue<string> Q;                // record all intermediate results
        unordered_set<string> visited;  // visited or unvisited
        Q.push(A);
        visited.insert(A);
        while(!Q.empty()){
            ans++;
            int len = Q.size();
            for(int k = 0; k < len; k++){ // scan all intermediate in each swap
                string str = Q.front();
                Q.pop();
                int i = 0;
                while(str[i] == B[i]) i++;  // former elements maybe same
                for(int j = i+1; j < B.size(); j++){
                    if(str[j] != B[i] || str[j] == B[j]) continue;  // keep B unchanged, and move j to make str[j]=B[i]
                    //swap str[i] with str[j]
                    string res = swap(str, i, j);
                    if(res == B) return ans;
                    if(visited.find(res) == visited.end()){
                        visited.insert(res);
                        Q.push(res);
                    }
                }
                
            }
        }
        return ans;
    }
};

