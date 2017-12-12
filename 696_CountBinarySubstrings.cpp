class Solution {
public:
    /**
    * Idea: count the number of contiguous same 0 or 1, eg, 00110011 =>2222
    * (2[2){2]2} can be regarded as 3 groups, further other 3 groups (01) or (10)
    * There are min{#group1, #group2} substrings between two adjacent groups
    */
    int countBinarySubstrings(string s) {
        int count = 1, output = 0;
        if(s.size() == 0){
            return output;
        }
        vector<int> help;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i-1]){
                ++count;
            }else{
                help.push_back(count);
                count = 1;
            }
        }
        help.push_back(count);

        for(int i = 0; i < help.size()-1; i++){
            output += min(help[i], help[i+1]);
        }
        return output;
    }
};