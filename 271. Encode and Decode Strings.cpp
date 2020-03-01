/*

271. Encode and Decode Strings -- Medium
http://www.leetfree.com/problems/encode-and-decode-strings.html

Design an algorithm to encode a list of strings to a string. 
The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}

Machine 2 (receiver) has the function:

vector<string> decode(string s) {
  //... your code
  return strs;
}

So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:

The string may contain any possible characters out of 256 valid ascii characters. 
Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. 
Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. 
You should implement your own encode/decode algorithm.

*/

/*
对一组string编码和解码
编码一个字符串用长度+特殊字符+字符串来编码。
解码时找到那个特殊字符串,然后前面又有了字符串的长度, 这样就不用考虑是否出现过这个字符了。
*/
class Codec {  
public:  
  
    // Encodes a list of strings to a single string.  
    string encode(vector<string>& strs) {  
        string res = "";
        for(auto str: strs){
            res += to_string((int)str.size()) + "$" + str;    // len + "$" + str
        }
        return res;
    }  
  
    // Decodes a single string to a list of strings.  
    vector<string> decode(string s) {  
        vector<string> result;
        int len = s.size(), pos = 0;
        while(pos < len)
        {
            int k = s.find('$', pos);         // find next "$" after pos
            num = stoi(s.substr(pos, k-pos)); // string --> integer
            result.push_back(s.substr(k+1, num));
            pos = k+num+1;                    // move pos
        }
        return result;        
    }  
};  
  
// Your Codec object will be instantiated and called as such:  
// Codec codec;  
// codec.decode(codec.encode(strs)); 

