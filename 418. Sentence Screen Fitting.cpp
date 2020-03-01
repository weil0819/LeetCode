/*

418. Sentence Screen Fitting -- Medium
http://www.leetfree.com/problems/sentence-screen-fitting.html

Given a rows x cols screen and a sentence represented by a list of words, 
findhow many times the given sentence can be fitted on the screen.

Note:

A word cannot be split into two lines.
The order of words in the sentence must remain unchanged.
Two consecutive words in a line must be separated by a single space.
Total words in the sentence won't exceed 100.
Length of each word won't exceed 10.
1 ≤ rows, cols ≤ 20,000.

Example 1:

Input:
rows = 2, cols = 8, sentence = ["hello", "world"]

Output: 
1

Explanation:
hello---
world---

The character '-' signifies an empty space on the screen.

Example 2:

Input:
rows = 3, cols = 6, sentence = ["a", "bcd", "e"]

Output: 
2

Explanation:
a-bcd- 
e-a---
bcd-e-

The character '-' signifies an empty space on the screen.
Example 3:

Input:
rows = 4, cols = 5, sentence = ["I", "had", "apple", "pie"]

Output: 
1

Explanation:
I-had
apple
pie-I
had--

The character '-' signifies an empty space on the screen

*/

/*
将sentence放到screen中，保证每个word不被拆分
求放满screen需要多少个sentence
*/
class Solution {  
public:  
	/*
	Method-I: 直接的方法是每次扫描一行，尝试能放几个，这样时间复杂度会高一点．
	Method-II: 把所有的字符串都加起来，然后每次看如果位移一整行的距离是否正好落在这个字符串的空格位置，
	如果不是的话就退后，直到遇到一个空格．
	*/
    int wordsTyping(vector<string>& sentence, int rows, int cols) {  
        string str;								// merge all words as one string
        for(auto val: sentence) str += val + " ";
        int len = str.size(), start = 0;
        for(int i = 0; i < rows; i++)
        {
            start += cols;
            if(str[start%len]==' ')				// if the-col position is ' ',put this word in current row
            {
                start++;
                continue;
            }
            while(start > 0 && str[(start-1)%len]!=' ') start--;	// else, put former word in current row
        }
        return start/len;
    }  
};  

