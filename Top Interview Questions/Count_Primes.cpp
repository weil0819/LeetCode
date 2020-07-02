/*
Count Primes

@date: July 2, 2020

Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

*/

class Solution {
public:
    // Property-1: prime n is not divisible by any number less than n
    // Property-2: 1 is not a prime
    // O(n^(1.5))
    int countPrimes(int n) {
        // declare an array to represent the element is not a prime
        vector<bool> notPrime(n);               // default is not prime
        int res = 0;
        for(int i = 2; i < n; i++) {
            if(notPrime[i] == false) {          // i must be prime
                res++;
                for(int j = 2; i*j < n; j++) { // calculate multiplication, must not be prime
                    notPrime[i*j] = true;
                }
            }
        }
        return res;
    }
};

