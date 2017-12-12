//===========================================================================================
// 593. Valid Square

// Given the coordinates of four points in 2D space, return whether the four points could construct a square.

// The coordinate (x,y) of a point is represented by an integer array with two integers.

// Example:
// Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
// Output: True
// Note:

// All the input integers are in the range [-10000, 10000].
// A valid square has four equal sides with positive length and four equal angles (90-degree angles).
// Input points have no order.
//===========================================================================================

class Solution {
public:
	/**
	* Idea: we directly compute the distance of any two points
	* Attention: distance should not be 0
	* 
	*/
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    	unordered_set<int> helper;
    	
        int disOneTwo = (p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]);        
        helper.insert(disOneTwo);
        int disOneThr = (p1[0]-p3[0])*(p1[0]-p3[0]) + (p1[1]-p3[1])*(p1[1]-p3[1]); 
        if(helper.find(disOneThr) == helper.end()){
        	helper.insert(disOneThr);
        }
        int disOneFou = (p1[0]-p4[0])*(p1[0]-p4[0]) + (p1[1]-p4[1])*(p1[1]-p4[1]); 
        if(helper.find(disOneFou) == helper.end()){
        	helper.insert(disOneFou);
        }        
        int disTwoThr = (p2[0]-p3[0])*(p2[0]-p3[0]) + (p2[1]-p3[1])*(p2[1]-p3[1]); 
        if(helper.find(disTwoThr) == helper.end()){
        	helper.insert(disTwoThr);
        }        
        int disTwoFou = (p2[0]-p4[0])*(p2[0]-p4[0]) + (p2[1]-p4[1])*(p2[1]-p4[1]); 
        if(helper.find(disTwoFou) == helper.end()){
        	helper.insert(disTwoFou);
        }        
        int disThrFou =(p3[0]-p4[0])*(p3[0]-p4[0]) + (p3[1]-p4[1])*(p3[1]-p4[1]); 
        if(helper.find(disThrFou) == helper.end()){
        	helper.insert(disThrFou);
        }
        if(helper.size() == 2 && helper.find(0) == helper.end()){
        	return true;
        }
        return false;        
    }
};