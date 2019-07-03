class Solution {
public:
    /**
    * Idea: set a carry value and visit each char from end to begin
    * How to compute the carry? carry = sum/10;
    * How to compute the sum of two values? sum = sum%10;
    */
    string addStrings(string num1, string num2) {
        int carry = 0, n = num1.size(), m = num2.size();
        int i = n-1, j = m-1;
        string output = "";
        while(i>=0 || j>=0 || carry!=0){
            int tmp = 0;
            if(i >= 0){
                tmp += (num1[i] - '0');
                i--;
            }
            if(j >= 0){
                tmp += (num2[j] - '0');
                j--;
            }
            tmp += carry;
            carry = tmp/10;
            tmp = tmp%10;
            output.append(to_string(tmp));
        }
        reverse(output.begin(), output.end());
        return output;
    }
};