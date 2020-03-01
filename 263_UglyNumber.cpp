class Solution {
public:
    /**
    * Idea:1.straightforward check current number is ugly number or not
    * ugly number can be divided by 2, 3 or 5 sequentially
    * 2.use an array to record sorted ugly number
    * 
    */
    bool isUgly(int num) {
        if(num <= 0){
            return false;
        }
        while(num%2 == 0){
            num /= 2;
        }
        while(num%3 == 0){
            num /= 3;
        }
        while(num%5 == 0){
            num /= 5;
        }
        return (num == 1);
    }
/*    
private:
    // return the index ugly number
    int getUglyNum(int index){
        if(index <= 0){
            return 0;
        }
        vector<int> uglySet;
        uglySet[0] = 1;
        int nextUglyIndex = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        while(nextUglyIndex < index){
            int minV = min(uglySet[p2]*2, uglySet[p3]*2, uglySet[p5]*2);
            uglySet[nextUglyIndex] = minV;
            while(uglySet[p2] * 2 < uglySet[nextUglyIndex]){
                p2++;
            }
            while(uglySet[p3] * 3 < uglySet[nextUglyIndex]){
                p3++;
            }
            while(uglySet[p5] * 5 < uglySet[nextUglyIndex]){
                p5++;
            } 
            nextUglyIndex++;
        }
        return uglySet[nextUglyIndex - 1];
    }
*/   
};