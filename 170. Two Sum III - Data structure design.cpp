/*

170. Two Sum III - Data structure design -- Easy
https://www.leetfree.com/problems/two-sum-iii-data-structure-design.html

Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

For example,
add(1); add(3); add(5);
find(4) -> true
find(7) -> false

*/

/*
问题：计算两个数字的和的类


使用hashmap记录<数字，对应的数量>
调用find()方法时，顺序遍历hashmap中的而每个key，
如果value-key存在于hashmap中，并且 value-key != key，那么就返回true
如果value-key存在于hashmap中，并且 value-key == key，且hashmap[key]>1，那么就返回true

*/

class TwoSum {
public:
    void add(int number) {
        ++m[number];
    }
    bool find(int value) {
        for (auto a : m) {
            int t = value - a.first;
            if ((t != a.first && m.count(t)) || (t == a.first && a.second > 1)) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_map<int, int> m;		// <number, #number>
};