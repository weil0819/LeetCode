/*

288. Unique Word Abbreviation -- Medium
http://www.leetfree.com/problems/unique-word-abbreviation.html


An abbreviation of a word follows the form <first letter><number><last letter>. 
Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n

Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. 
A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example: 

Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> 
false

isUnique("cart") -> 
true

isUnique("cane") -> 
false

isUnique("make") -> 
true

*/


/*
已知字典dictionary，判断word的缩写在dictionary中是否是唯一的

三种情况：

1. dictionary = {"dear"},  isUnique("door") -> false

2. dictionary = {"door", "door"}, isUnique("door") -> true

3. dictionary = {"dear", "door"}, isUnique("door") -> false

我们在遇到哈希表中没有当前缩写形式的时候，将该缩写形式和当前单词建立映射，
如果该缩写形式应经存在，那么我们看如果映射的单词不是当前单词，
我们将映射单词改为空字符串，这样做的原因是，在对于第三种情况dictionary = {"dear", "door"}时，
遍历dear时，建立d2r和dear的映射，当遍历到door的时候，由于door和dear不同，
我们将映射改为d2r和“”映射，而对于第二种情况 dictionary = {"door", "door"}，
保留d2r和door的映射，那么这样在判断door是否unique时，就可以区别第二种和第三种情况了

*/
class ValidWordAbbr {  
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (auto a : dictionary) {
            string k = a[0] + to_string(a.size() - 2) + a.back();
            if (m.find(k) != m.end() && m[k] != a) m[k] = "";
            else m[k] = a;
        }
    }
    bool isUnique(string word) {
        string k = word[0] + to_string(word.size() - 2) + word.back();
        return m.find(k) == m.end() || m[k] == word;
    }
private:
    unordered_map<string, string> m;
};  
  
  
// Your ValidWordAbbr object will be instantiated and called as such:  
// ValidWordAbbr vwa(dictionary);  
// vwa.isUnique("hello");  
// vwa.isUnique("anotherWord"); 

