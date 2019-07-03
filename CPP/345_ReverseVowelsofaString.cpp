class Solution {
public:
    /**
    * Idea: As we all know, vowels contain a, e, i, o, u
    * We set two points which point to beginning and ending element
    * that is, p----> AND <----q
    * 
    */
    string reverseVowels(string s) {
        int n = s.size();
        int low = 0, high = n-1;
        vector<char> help;
        help.push_back('a');
        help.push_back('A');
        help.push_back('e');
        help.push_back('E');
        help.push_back('i');
        help.push_back('I');
        help.push_back('o');
        help.push_back('O');
        help.push_back('u');
        help.push_back('U');
        while(low < high){
            while(low < high && find(help.begin(), help.end(), s[low]) == help.end()){
                low++;
            }
            while(low < high && find(help.begin(), help.end(), s[high]) == help.end()){
                high--;
            }
            char tmp = s[low];
            s[low] = s[high];
            s[high] = tmp;
            low++;
            high--;
        }
        return s;
    }
};