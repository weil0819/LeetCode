class Solution {
public:
    /**
    * Idea: use an unordered_map<string, int> to record the restaurant and position in list1
    * and find the pair which has least list index sum
    * Attention: there will be several pairs 
    */
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> help;
        for(int i = 0; i < list1.size(); i++){
            help[list1[i]] = i;
        }
        vector<string> output;
        int minSum = INT_MAX;
        for(int i = 0; i < list2.size(); i++){
            if(help.find(list2[i]) != help.end()){
                int sum = i + help.find(list2[i])->second;
                if(sum < minSum){
                    minSum = sum;
                }
            }
        }
        
        for(int i = 0; i < list2.size(); i++){
            if(help.find(list2[i]) != help.end()){
                int sum = i + help.find(list2[i])->second;
                if(sum == minSum){
                    output.push_back(list2[i]);
                }
            }            
        }
        return output;
    }
};