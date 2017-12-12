class Solution {
public:
    /**
    * Idea: first we should sort array g and s, and then compare each element in them
    * If g[i] < s[j] => ++content and i++, j++; else j++
    */
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, content = 0;
        while(i < g.size() && j < s.size()){
            if(g[i] <= s[j]){
                ++content;
                ++i;
                ++j;
            }else{
                ++j;
            }
        }
        return content;
    }
};
