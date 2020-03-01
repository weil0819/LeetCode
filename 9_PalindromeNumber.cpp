//===========================================================================================
// 9. Palindrome Number
// Determine whether an integer is a palindrome. Do this without extra space.

// click to show spoilers.

// Some hints:
// Could negative integers be palindromes? (ie, -1)
// If you are thinking of converting the integer to string, note the restriction of using extra space.
// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
// There is a more generic way of solving this problem.
//===========================================================================================

class Solution {
public:
    /**
    * Idea: negative integers are not palindromes and 0-9 must be palindromes, any number with tail 0 must not be palindromes
    * eg, 132231 is a palindrome
    * we should know the length of that integer and then compare the i vs. n-1-i
    * 132231/10 = 13223...(1), 13223/10 = 1322...(3), 1322/10 = 132...(2), 
    * we can combine the (1)(2)(3) as 132 which is equal to the remaining value
    * 
    */
    bool isPalindrome(int x) {
        if(x < 0){          // negative is not palindromes
            return false;        
        }
        if(x < 10){         // any number less than 10
            return true;
        }
        if(x%10 == 0){      // any number with tail 0
            return false;
        }
        int tmp = 0;
        while(tmp < x){
            tmp = tmp*10 + x%10;        //when tmp=1 ==> tmp=10+3=13; when tmp=13, ==> tmp=13*10+2=132
            x /= 10;
        }
        
        return (tmp == x) || (tmp/10 == x); // when x=121
    }
};