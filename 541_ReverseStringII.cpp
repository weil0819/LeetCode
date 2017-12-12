class Solution {
public:
    /**
    * Idea: we set two points, one is k before another one
    * p points to i and q points to i+k-1,
    * then p jumps to i+2*k
    */
    string reverseStr(string s, int k) {
        int n = s.size();
        for(int i = 0; i < n;){
            int p = i;
            int q = n > (i+k-1) ? (i+k-1) : (n-1);
            while(p < q){
                swap(s[p], s[q]);
                p++;
                q--;
            }
            i += 2*k;
        }
        return s;
    }
};