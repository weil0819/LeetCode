//===========================================================================================
// 38. Count and Say
// The count-and-say sequence is the sequence of integers with the first five terms as following:

// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
// Given an integer n, generate the nth term of the count-and-say sequence.

// Note: Each term of the sequence of integers will be represented as a string.

// Example 1:

// Input: 1
// Output: "1"
// Example 2:

// Input: 4
// Output: "1211"
//===========================================================================================

class Solution {
public:
    /**
    * Idea: use a queue<int> to record the integers of previous row
    * each time, we visit the stable length of queue
    * 
    */
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        queue<int> help;
        help.push(1);
        help.push(1);
        for(int i = 3; i <= n; i++){   
            int fir = help.front(), count = 1, len = help.size();
            help.pop();
            for(int j = 1; j < len; j++){
                int tmp = help.front();
                help.pop();
                if(fir == tmp){
                    ++count;
                    if(j == len-1){
                        help.push(count);
                        help.push(fir);
                    }
                }else{
                    help.push(count);
                    help.push(fir);
                    count = 1;
                    fir = tmp;
                    if(j == len-1){
                        help.push(count);
                        help.push(fir);
                    }                    
                }
            }
        }
        string output = "";
        while(!help.empty()){
            output.append(to_string(help.front()));
            help.pop();
        }
        return output;
    }
};