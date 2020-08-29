/*
Validate IP Address

@date: June 16, 2020

Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.

*/

class Solution {
public:
    string validIPAddress(string IP) {
        if(isValidIP4(IP)) return "IPv4";
        else if(isValidIP6(IP)) return "IPv6";
        return "Neither";
    }
    
private:
    bool isValidIP4(string IP) {
        if(IP.size() < 7 || IP.size() > 15 || IP[0] == '0') return false;
        if(IP.substr(0,4).find('.') == string::npos) return false;
        string block = "";
        int cnt = 0;
        for(int i = 0; i < IP.size(); i++){
            if(IP[i] <= '9' && IP[i] >= '0'){
                block = block + IP[i];
            }else if(IP[i] == '.'){
                if(block.size() > 1 && block.front() == '0') return false;
                if(block.size() == 0 || block.size() > 3 || stoi(block) > 255 || stoi(block) < 0) return false;                
                block = "";
                ++cnt;
            }else{
                return false;
            }            
        }
        if(block.size() > 1 && block.front() == '0') return false;
        if(block.size() == 0 || block.size() > 3 || stoi(block) > 255 || stoi(block) < 0) return false;
        if(cnt != 3) return false;
        return true;
    }
    
    bool isValidIP6(string IP) {
        if(IP.size() > 39 || IP.size() < 15) return false;
        if(IP.substr(0,5).find(':') == string::npos) return false;
        string block = "";
        int cnt = 0;
        for(int i = 0; i < IP.size(); i++){
            if((IP[i] <= '9' && IP[i] >= '0') || (IP[i] >= 'a' && IP[i] <= 'f') || (IP[i] >= 'A' && IP[i] <= 'F')){
                block = block + IP[i];
            }else if(IP[i] == ':'){
                if(block.size() > 4 || block.size() == 0) return false;                
                block = "";
                ++cnt;
            }else{
                return false;
            }            
        }
        if(block.size() > 4 || block.size() == 0) return false;
        if(cnt != 7){
            return false;
        }
        return true;
    }
};

