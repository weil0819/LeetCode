//===========================================================================================
// 399. Evaluate Division
// Equations are given in the format A / B = k, where A and B are variables represented as strings, 
// and k is a real number (floating point number). Given some queries, return the answers. 
// If the answer does not exist, return -1.0.

// Example:
// Given a / b = 2.0, b / c = 3.0. 
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
// return [6.0, 0.5, -1.0, 1.0, -1.0].

// The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , 
// where equations.size() == values.size(), and the values are positive. This represents the equations. 
// Return vector<double>.

// According to the example above:

// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
// The input is always valid. You may assume that evaluating the queries will result in no division by zero 
// and there is no contradiction.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: Image a/b = k as a link between node a and b, the weight from a to b is k, 
	* the reverse link is 1/k. Query is to find a path between two nodes.
    * 
	*/
    vector<double> calcEquation(vector<pair<string, string> > equations, vector<double>& values, 
    	vector<pair<string, string> > queries) {

    	unordered_map<string, vector<string> > pairs;
    	unordered_map<string, vector<double> > valuePairs;
    	for(int i = 0; i < equations.size(); i++){
    		//
    		if(pairs.find(equations[i].first) == pairs.end()){
    			 vector<string> tmp1;
    			 tmp1.push_back(equations[i].second);
    			 pairs.insert(make_pair(equations[i].first, tmp1));
    			 vector<double> tmp2;
    			 tmp2.push_back(values[i]);
    			 valuePairs.insert(make_pair(equations[i].first, tmp2));
    		}else{
    			pairs.find(equations[i].first)->second.push_back(equations[i].second);
    			valuePairs.find(equations[i].first)->second.push_back(values[i]);
    		}
    		//
    		if(pairs.find(equations[i].second) == pairs.end()){
    			 vector<string> tmp1;
    			 tmp1.push_back(equations[i].first);
    			 pairs.insert(make_pair(equations[i].second, tmp1));
    			 vector<double> tmp2;
    			 tmp2.push_back(1/values[i]);
    			 valuePairs.insert(make_pair(equations[i].second, tmp2));
    		}else{
    			pairs.find(equations[i].second)->second.push_back(equations[i].first);
    			valuePairs.find(equations[i].second)->second.push_back(1/values[i]);
    		}
    	}

    	vector<double> res(queries.size(), -1.0);
    	for(int i = 0; i < queries.size(); i++){
    		unordered_set<string> S;
    		res[i] = dfsUtil(queries[i].first, queries[i].second, pairs, valuePairs, S, 1.0);
    	}
        
        return res;
    }

    double dfsUtil(string fir, string sec, unordered_map<string, vector<string> > pairs, 
    	unordered_map<string, vector<double> > valuePairs, unordered_set<string>& S, double val){

    	if(S.find(fir) != S.end()){
    		return -1.0;
    	}
    	if(pairs.find(fir) == pairs.end()){
    		return -1.0;
    	}
    	if(fir == sec){
    		return val;
    	}
    	S.insert(fir);

    	vector<string> pairsVec = pairs[fir];
    	vector<double> valuePairsVec = valuePairs[fir];

    	double tmp = -1.0;
    	for(int i = 0; i < pairsVec.size(); i++){
    		tmp = dfsUtil(pairsVec[i], sec, pairs, valuePairs, S, val*valuePairsVec[i]);
    		if(tmp != -1.0){
    			break;
    		}
    	}
    	S.erase(fir);
    	return tmp;
    }
};
