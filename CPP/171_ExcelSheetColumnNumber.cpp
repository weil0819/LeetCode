class Solution {
public:
    /**
    * Idea: just like 26-ary prolem
    * AB = 26+2, AAB = 27*26+2, ABA = 28*26+1, ACB = 29*26+2
    * that is, num = num*26 + s[i]-'A'+1
    */
    int titleToNumber(string s) {
        int num = 0;
        for(int i = 0; i < s.size(); i++){
            num = num*26 + s[i]-'A'+1;
        }
        return num;
    }
};