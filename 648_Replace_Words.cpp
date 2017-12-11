//===========================================================================================
// 648. Replace Words

// In English, we have a concept called root, which can be followed by some other words to form another longer word - 
// let's call this word successor. For example, the root an, followed by other, which can form another word another.

// Now, given a dictionary consisting of many roots and a sentence. 
// You need to replace all the successor in the sentence with the root forming it. 
// If a successor has many roots can form it, replace it with the root with the shortest length.

// You need to output the sentence after the replacement.

// Example 1:
// Input: dict = ["cat", "bat", "rat"]
// sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
// Note:
// The input will only have lower-case letters.
// 1 <= dict words number <= 1000
// 1 <= sentence words number <= 1000
// 1 <= root length <= 100
// 1 <= sentence words length <= 1000
//===========================================================================================

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
	/**
	* Idea: we use map<int, vector<string> > to record <the length of root, the set of roots>
    * and then scan sentence to check each word whether it is contains a prefix of dicts with shortest length
	* 
	*/
    string replaceWords(vector<string>& dict, string sentence) {
        map<int, vector<string> > helper;
        for(int i = 0; i < dict.size(); i++){
        	if(helper.find(dict[i].size()) == helper.end()){
        		vector<string> tmp;
        		tmp.push_back(dict[i]);
        		helper.insert(make_pair(dict[i].size(), tmp));
        	}else{
        		helper.find(dict[i].size())->second.push_back(dict[i]);
        	}
        }

        string str = "";            // record each word
        string res = "";            // return value
        for(int i = 0; i < sentence.size(); i++){
        	if((sentence[i]-'a' < 26 && sentence[i]-'a' >= 0) || (sentence[i]-'A' < 26 && sentence[i]-'A' >= 0)){
        		string tmp = "";
        		tmp = tmp + sentence[i];
        		str.append(tmp);
                if(i == sentence.size()-1){
                    res.append(check(helper, str));
                }
        	}else{        		
        		res.append(check(helper, str));
        		str.clear();
        		string tmp = "";
        		tmp = tmp + sentence[i];
        		res.append(tmp);
        	}
        }
        return res;
    }
    string check(map<int, vector<string> > helper, string str){
    	for(map<int, vector<string> >::iterator it = helper.begin(); it != helper.end(); ++it){
    		int len = it->first;
    		for(int i = 0; i < it->second.size(); i++){
    			if(str.substr(0, len) == it->second[i]){
    				return it->second[i];
    			}
    		}
    	}
    	return str;
    }
};

int main(){
	Solution sn;
	vector<string> dict;
	dict.push_back("cat");
	dict.push_back("bat");
	dict.push_back("rat");
	string sentence = "the cat was rat by the bat";
	cout<<sn.replaceWords(dict, sentence)<<endl;
	return 0;
}