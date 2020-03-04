/*
406. Queue Reconstruction by Height -- Medium
https://leetcode.com/problems/queue-reconstruction-by-height/ 

Suppose you have a random list of people standing in a queue. 
Each person is described by a pair of integers (h, k), 
where h is the height of the person and k is the number of people in front of this person 
who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

 
Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]

*/

bool myComp(vector<int>& P1, vector<int>& P2) {
    if(P1[0] > P2[0]) return true;
    else if(P1[0] < P2[0]) return false;
    else return P1[1] < P2[1];
}

class Solution {
public:
    // Sort the list in descending order by height and ascending order by k
    // Insert queue from the shortest one
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int N = people.size();
        if(N <= 1) return people;
        
        vector<vector<int> > res;
        res.reserve(N);
        sort(people.begin(), people.end(), myComp);
        // [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
        // [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
        for(int i = 0; i < N; i++) {
            int h = people[i][0], k = people[i][1];
            vector<vector<int> >::iterator iter = res.begin();
            res.insert(iter+k, people[i]);            
        }
        
        return res;
    }
};
