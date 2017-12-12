class Solution {
public:
    /**
    * Idea: use a unordered_map to record the alphabet and its number
    * If s.size() != t.size(), return false
    */
    bool isAnagram(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m){
            return false;
        }
        unordered_map<char, int> help;
        for(int i = 0; i < n; i++){
            ++help[s[i]];
        }
        for(int i = 0; i < m; i++){
            if(help.find(t[i]) == help.end()){
                return false;
            }else{
                help[t[i]]--;
                if(help[t[i]] < 0){
                    return false;
                }
            }
        }
        return true;
    }
};