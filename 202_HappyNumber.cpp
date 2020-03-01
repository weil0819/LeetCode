class Solution {
public:
    /**
    * Idea: we need to construct a function to calculate the squares
    * and then use a unordered_set to record the square sum
    * once we calculate a value that exists in unordered_set, stop
    */
    bool isHappy(int n) {
        if(n == 1){
            return 1;
        }
        unordered_set<int> help;
        while(help.find(n) == help.end()){
            help.insert(n);
            int tmp = squareSum(n);
            if(tmp == 1){
                return true;
            }else{
                n = tmp;
            }            
        }
        return false;
        
    }
    
    int squareSum(int n){
        int sum = 0;
        while(n){
            int tmp = n%10;
            sum += tmp*tmp;
            n = n/10;
        }
        return sum;
    }
};