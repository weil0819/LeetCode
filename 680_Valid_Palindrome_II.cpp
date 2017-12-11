//===========================================================================================
// 680. Valid Palindrome II
// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

// Example 1:
// Input: "aba"
// Output: True
// Example 2:
// Input: "abca"
// Output: True
// Explanation: You could delete the character 'c'.
// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.
//===========================================================================================

class Solution {
private:
    bool checkPalindrome(string s, int head, int tail){
        while(head <= tail){
            if(s[head] == s[tail]){
                head++;
                tail--;
            }else{
                break;
            }
        }
        if(head >= tail){
            return true;            
        }else{
            return false;
        }
    }
public:
    /**
    * Idea: we set two points to point to the head and tail of string
    * When it comes to s[head] != s[tail], we need to consider two cases:
    * 1) delete s[head], we continue to visit s[head+1]
    * 2) delete s[tail], we continue to visit s[tail-1]
    * 
    */
    bool validPalindrome(string s) {
        int n = s.size();
        if(n == 1){
            return true;
        }
        int head = 0, tail = n-1;
        while(head <= tail){
            if(s[head] == s[tail]){
                head++;
                tail--;
            }else{
                break;
            }
        }
        if(head >= tail){
            return true;
        }else{
            return checkPalindrome(s, head+1, tail) || checkPalindrome (s, head, tail-1);
        }        
    }
};