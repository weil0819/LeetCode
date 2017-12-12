class Solution {
public:
    /**
    * Idea: back-tracking the digits and set a carry variable
    * 
    */
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        vector<int> output;
        for(int i = n-1; i >= 0; i--){
            int tmp = 0;
            if(i == n-1){
                tmp = digits[i] + 1 + carry;
            }else{
                tmp = digits[i] + carry;
            }
            output.push_back(tmp%10);
            carry = tmp / 10;
        }
        if(carry != 0){
            output.push_back(carry);
        }
        reverse(output.begin(), output.end());
        return output;
    }
};