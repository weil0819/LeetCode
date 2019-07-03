class Solution {
public:
    /**
    * Idea: for a certain point, we record the distance and #point which have same distance
    * If #point >= 2, we can get #point*(#point-1) solutions 
    * 
    */
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
        int output = 0;
        for(int i = 0; i < n; i++){
            unordered_map<int, int> help;
            for(int j = 0; j < n; j++){
                ++help[pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2)];
            }
            for(unordered_map<int, int>::iterator it = help.begin(); it != help.end(); ++it){
                output += it->second*(it->second-1);
            }
        }
        return output;
    }
};