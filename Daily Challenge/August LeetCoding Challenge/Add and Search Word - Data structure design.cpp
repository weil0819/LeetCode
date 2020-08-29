/*
Add and Search Word - Data structure design

@date: Aug 5, 2020

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

Example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

*/

class TrieNode{
public:
    bool isEndofWord;
    TrieNode* next[26];

    TrieNode(bool b = false){
        memset(next, 0,sizeof(next));
        isEndofWord = b;
    }    
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* p = root;
        for(int i = 0; i < word.size(); i++){
            if(p->next[word[i]-'a'] == NULL){
                p->next[word[i]-'a'] = new TrieNode();
            }
            p = p->next[word[i]-'a'];
        }
        p->isEndofWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return find(word, root);
    }
    
private:
    TrieNode* root;
    
    bool find(string word, TrieNode* node){
        TrieNode* p = node;
        for(int i = 0; i < word.size(); i++){
            if(word[i] != '.' && p != NULL){
                p = p->next[word[i]-'a'];
            }else if(word[i] == '.' && p != NULL){
                TrieNode* tmp = p;
                for(int j = 0; j < 26; j++){
                    p = tmp->next[j];
                    if(find(word.substr(i+1), p)){      // recursive call 
                        return true;
                    }
                }
            }
        }
        return p != NULL && p->isEndofWord == true;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
