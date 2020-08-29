/*
Word Search II

@date: June 30, 2020

Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

 

Example:

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
 

Note:

All inputs are consist of lowercase letters a-z.
The values of words are distinct.

*/


class TrieNode{
public:
    vector<TrieNode*> next;
    string word;
    
    // constructor function
    TrieNode(): next(26){}    
};

class Solution {
public:
    // Trie
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        TrieNode* root = buildTrie(words);
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[i].size(); j++) {
                DFSUtil(board, i, j, root, res);
            }
        }
        return res;
    }
private:
    // Use trie to store word list, root is empty, and all middle nodes are empty, only leaves have word
    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto word: words) {
            TrieNode* p = root;
            for(auto w: word) {
                int idx = w - 'a';
                if(p->next[idx] == NULL) p->next[idx] = new TrieNode();
                p = p->next[idx];
            }
            p->word = word;
        }
        return root;
    }
    
    void DFSUtil(vector<vector<char> >& board, int i, int j, TrieNode* p, vector<string>& res) {
        char c = board[i][j];
        if(c == '#' || p->next[c-'a'] == NULL) return;
        p = p->next[c-'a'];
        if(p->word != "") {        // find valid word
            res.push_back(p->word);
            p->word = "";          // no duplicate
        }
        board[i][j] = '#';
        // scan all four directions
        if (i > 0) DFSUtil(board, i - 1, j ,p, res); 
        if (j > 0) DFSUtil(board, i, j - 1, p, res);
        if (i < board.size() - 1) DFSUtil(board, i + 1, j, p, res); 
        if (j < board[0].size() - 1) DFSUtil(board, i, j + 1, p, res); 
        board[i][j] = c;            // recovery   
    }
    
};
