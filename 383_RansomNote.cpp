class Solution {
public:
    /**
    * Idea: there should be enough letters in magazine for constructing the ransom note
    * We should count the #letters in magazine and then traverse ransomNode
    * Here, we use a unordered_map<char, int> to record the letter and its number
    */
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> help;
        for(int i = 0; i < magazine.size(); i++){
            if(help.find(magazine[i]) != help.end()){
                ++help.find(magazine[i])->second;
            }else{
                help.insert(make_pair(magazine[i], 1));
            }
        }
        for(int i = 0; i < ransomNote.size(); i++){
            if(help.find(ransomNote[i]) != help.end()){
                --help.find(ransomNote[i])->second;
                if(help.find(ransomNote[i])->second < 0){
                    return false;
                }
            }else{
                return false;
            }
        }
        return true;
    }
};