/*
Prison Cells After N Days

@date: July 3, 2020

There are 8 prison cells in a row, and each cell is either occupied or vacant.

Each day, whether the cell is occupied or vacant changes according to the following rules:

If a cell has two adjacent neighbors that are both occupied or both vacant, then the cell becomes occupied.
Otherwise, it becomes vacant.
(Note that because the prison is a row, the first and the last cells in the row can't have two adjacent neighbors.)

We describe the current state of the prison in the following way: cells[i] == 1 if the i-th cell is occupied, else cells[i] == 0.

Given the initial state of the prison, return the state of the prison after N days (and N such changes described above.)

 

Example 1:

Input: cells = [0,1,0,1,1,0,0,1], N = 7
Output: [0,0,1,1,0,0,0,0]
Explanation: 
The following table summarizes the state of the prison on each day:
Day 0: [0, 1, 0, 1, 1, 0, 0, 1]
Day 1: [0, 1, 1, 0, 0, 0, 0, 0]
Day 2: [0, 0, 0, 0, 1, 1, 1, 0]
Day 3: [0, 1, 1, 0, 0, 1, 0, 0]
Day 4: [0, 0, 0, 0, 0, 1, 0, 0]
Day 5: [0, 1, 1, 1, 0, 1, 0, 0]
Day 6: [0, 0, 1, 0, 1, 1, 0, 0]
Day 7: [0, 0, 1, 1, 0, 0, 0, 0]

Example 2:

Input: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output: [0,0,1,1,1,1,1,0]
 

Note:

cells.length == 8
cells[i] is in {0, 1}
1 <= N <= 10^9

*/

class Solution {
public:
    // Inspired by @xiaogugu
    // https://leetcode.com/problems/prison-cells-after-n-days/discuss/266854/Java%3A-easy-to-understand
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        if(cells.size() == 0 || N <= 0) return cells;
        
        int cycle = 0;          // length of the cycle
        bool hasCycle = false;  // whether cycle exists
        unordered_set<string> helper;   // different cells
        for(int i = 0; i < N; i++) {
            vector<int> temp = nextDay(cells);
            string key(temp.begin(), temp.end());
            if(helper.find(key) == helper.end()) {      // not in set
                helper.insert(key);
                cycle++;
            } else {    // in set, a cycle
                hasCycle = true;
                break;
            }
            cells = temp;   // last cell
        }
        if(hasCycle) {
            N %= cycle;
            for(int i = 0; i < N; i++) {
                cells = nextDay(cells);
            }
        }
        
        return cells;        
    }
private:
    vector<int> nextDay(vector<int>& cells) {
        vector<int> res(cells.size(), 0);
        for(int i = 1; i < cells.size()-1; i++) {
            if(cells[i-1] == cells[i+1]) res[i] = 1;
        }
        return res;
    }
};
