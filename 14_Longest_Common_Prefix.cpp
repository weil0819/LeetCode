//===========================================================================================
// 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: we first find the common prefix "comStr" of the first two strings
	* and then find common prefix between "comStr" and strs[i]
	* 
	*/
    string longestCommonPrefix(vector<string>& strs) {
        string comStr = "";
        int n = strs.size(), i = 0;
        if(n == 0){
            return "";
        }
        if(n == 1){
            return strs[0];
        }

        // compute the prefix of the first two strings
        while(i < strs[0].size() && i < strs[1].size()){
        	if(strs[0][i] == strs[1][i]){
        		comStr = comStr + strs[0][i];
        	}else{
        		break;
        	}
            i++;
        }
        if(comStr == ""){
            return "";
        }
        for(int i = 2; i < n; i++){
        	string tmp = "";
        	int j = 0;
        	while(j < comStr.size() && j < strs[i].size()){
        		if(strs[i][j] == comStr[j]){
                    tmp = tmp + comStr[j];
        		}else{
        			break;
        		}
                j++;
        	}
        	comStr = tmp;
        }

        return comStr;
    }
};