class Solution {
public:
    /**
    * Idea: for a positive number, make the number divide by 16
    * Here, a = 10, b = 11, c = 12, d = 13, e = 14, f = 15
    * From others' view, each time we take a look at the last four digits of the binary version of the input,
    * and maps that to a hex char, shift the input to the right by 4 bits, do it again, until input becomes 0.
    * eg, 18 = 0001,0010(binary) = 12(hex)
    * 
    */
    string toHex(int num) {
        if(num == 0){
            return "0";
        }
        vector<char> toHexChar = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        string result = "";
        while(num != 0){
            result = toHexChar[num&15] + result;    //num&15 means calculate the value of the last four digits  
            num = (unsigned int)num>>4;             //each time divide num by 16
        }
        return result;
    }
};