/*
Implement Trie (Prefix Tree)

@date: May 14, 2020

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

*/

class TrieNode {
public:
    TrieNode* next[26];
    bool isEndofWord;
    
    // Constructer (not default)
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        isEndofWord = b;
    }   
};

class Trie {
private:
    TrieNode* root;
    
    // return the last char in word which already exits in Trie
    TrieNode* find(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            if(p != NULL) {
                p = p->next[word[i]-'a'];
            }
        }
        return p;
    }
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++) {
            if(p->next[word[i]-'a'] == NULL) {
                p->next[word[i]-'a'] = new TrieNode();
            }
            p = p->next[word[i]-'a'];
        }
        p->isEndofWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* p = find(word);
        return p != NULL && p->isEndofWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* p = find(prefix);
        return p != NULL;        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

