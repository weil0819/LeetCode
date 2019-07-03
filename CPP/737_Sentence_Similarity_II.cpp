//===========================================================================================
// 737. Sentence Similarity II

// Given two sentences words1, words2 (each represented as an array of strings), 
// and a list of similar word pairs pairs, determine if two sentences are similar.

// For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, 
// if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

// Note that the similarity relation is transitive. For example, if "great" and "good" are similar, 
// and "fine" and "good" are similar, then "great" and "fine" are similar.

// Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" 
// and "great" being similar.

// Also, a word is always similar with itself. For example, the sentences words1 = ["great"], 
// words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

// Finally, sentences can only be similar if they have the same number of words. 
// So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"].

// Note:

// The length of words1 and words2 will not exceed 1000.
// The length of pairs will not exceed 2000.
// The length of each pairs[i] will be 2.
// The length of each words[i] and pairs[i][j] will be in the range [1, 20].
//===========================================================================================

class Solution {
public:
	/**
	* Idea: use a unordered_map<string, unordered_set<string> > to record the <word, list of similar words>
	* 
	*/
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string> > pairs) {
        int n = words1.size(), m = words2.size();
        if(n != m){
        	return false;
        }
        unordered_map<string, unordered_set<string> > helper;
        for(int i = 0; i < pairs.size(); i++){
        	//
        	if(helper.find(pairs[i].first) == helper.end()){
        		unordered_set<string> tmp;
        		tmp.insert(pairs[i].second);
        		helper.insert(make_pair(pairs[i].first, tmp));
        	}else{
        		helper.find(pairs[i].first)->second.insert(pairs[i].second);
        	}
        	//
        	if(helper.find(pairs[i].second) == helper.end()){
        		unordered_set<string> tmp;
        		tmp.insert(pairs[i].first);
        		helper.insert(make_pair(pairs[i].second, tmp));
        	}else{
        		helper.find(pairs[i].second)->second.insert(pairs[i].first);
        	}       	
        }

        for(int i = 0; i < words1.size(); i++){
        	string str1 = words1[i];
        	string str2 = words2[i];
        	stack<string> S;
        	S.push(str1);
        	unordered_set<string> visited;
        	bool flag = false;
        	while(!S.empty()){
        		string tmp = S.top();
        		S.pop();
        		if(tmp == str2){
        			flag = true;
        			break;
        		}
        		if(helper.find(tmp) != helper.end()){
        			for(unordered_set<string>::iterator it = helper.find(tmp)->second.begin(); 
        				it != helper.find(tmp)->second.end(); ++it){

        				if(visited.find(*it) == visited.end()){
        					S.push(*it);
        					visited.insert(*it);
        				}
        			}
        		}
        	}
        	if(!flag){
        		return false;
        	}
        }
        return true;
    }
};

