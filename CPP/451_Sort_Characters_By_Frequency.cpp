//==========================================================================================
// 451. Sort Characters By Frequency

// Given a string, sort it in decreasing order based on the frequency of characters.

// Example 1:

// Input:
// "tree"

// Output:
// "eert"

// Explanation:
// 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
// Example 2:

// Input:
// "cccaaa"

// Output:
// "cccaaa"

// Explanation:
// Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
// Note that "cacaca" is incorrect, as the same characters must be together.
// Example 3:

// Input:
// "Aabb"

// Output:
// "bbAa"

// Explanation:
// "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.
//==========================================================================================
#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: we can use a unordered_map<char, int> to record the <char, #char>
	* and then use a second map<int, vector<char> > to record the <#char, chars>
	* 
	*/
    string frequencySort(string s) {
        string output = "";        
        int n = s.size();
        if(n == 0){
        	return output;
        }
        unordered_map<char, int> charNum;
        for(int i = 0; i < n; i++){
        	if(charNum.find(s[i]) == charNum.end()){
        		charNum.insert(make_pair(s[i], 1));
        	}else{
        		++charNum[s[i]];
        	}
        }

        map<int, vector<char> > numChars;
        for(unordered_map<char, int>::iterator it = charNum.begin(); it != charNum.end(); ++it){
        	if(numChars.find(it->second) == numChars.end()){
        		vector<char> tmp;
        		tmp.push_back(it->first);
        		numChars.insert(make_pair(it->second, tmp));
        	}else{
        		numChars.find(it->second)->second.push_back(it->first);
        	}
        }

        for(map<int, vector<char> >::reverse_iterator rit = numChars.rbegin(); rit != numChars.rend(); ++rit){
        	int len = rit->first;
        	for(vector<char>::iterator it = rit->second.begin(); it != rit->second.end(); ++it){    
        		int ind = len;    		
        		while(ind > 0){
        			//output = output + *it;
        			output.append(1, *it);
        			ind--;
        		}
        	}
        }

        return output;
    }
};



int main(){
	Solution sn;
	cout<<sn.frequencySort("tree")<<endl;
	return 0;
}