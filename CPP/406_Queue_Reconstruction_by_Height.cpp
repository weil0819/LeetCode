//==========================================================================================
// 406. Queue Reconstruction by Height

// Suppose you have a random list of people standing in a queue. 
// Each person is described by a pair of integers (h, k), 
// where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h.
// Write an algorithm to reconstruct the queue.

// Note:
// The number of people is less than 1,100.

// Example

// Input:
// [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

// Output:
// [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
//==========================================================================================
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	/**
	* Idea: top-to-bottom method, we should consider the largest height firstly
	* Here, we can use insert() in vector STL
    * 
	*/
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
        vector<pair<int, int> > output;
        output.reserve(people.size());
        map<int, vector<int> > heigPos;                 // <height, positions of all elements with above height>
        for(int i = 0; i < people.size(); i++){
        	if(heigPos.find(people[i].first) == heigPos.end()){
        		vector<int> tmp;
        		tmp.push_back(i);
        		heigPos.insert(make_pair(people[i].first, tmp));
        	}else{
        		heigPos.find(people[i].first)->second.push_back(i);
        	}
        }

        for(map<int, vector<int> >::reverse_iterator rit = heigPos.rbegin(); rit != heigPos.rend(); ++rit){        	
            sortPos(people, rit->second);
            for(int i = 0; i < rit->second.size(); i++){
                int k = people[rit->second[i]].second;
                vector<pair<int, int> >::iterator it = output.begin();
                output.insert(it+k, people[rit->second[i]]);                
            }
        }

        return output;
    }

    void sortPos(vector<pair<int, int> > people, vector<int>& pos){
        int n = pos.size();
        for(int i = 0; i < n-1; i++){
            for(int j = 0; j < n-i-1; j++){
                if(people[pos[j]].second > people[pos[j+1]].second){
                    int tmp = pos[j];
                    pos[j] = pos[j+1];
                    pos[j+1] = tmp;
                }
            }
        }
    }
};

int main(){
	Solution sn;
	vector<pair<int, int> > people;
	people.push_back(pair<int, int>(7,0));
	people.push_back(pair<int, int>(4,4));
	people.push_back(pair<int, int>(7,1));
	people.push_back(pair<int, int>(5,0));
	people.push_back(pair<int, int>(6,1));
	people.push_back(pair<int, int>(5,2));
	vector<pair<int, int> > output = sn.reconstructQueue(people);
    for(int i = 0; i < output.size(); i++){
        cout<<output[i].first<<", "<<output[i].second<<endl;
    }
	return 0;
}
