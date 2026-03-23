// Find XOR of numbers from L to R.
// Difficulty: EasyAccuracy: 50.0%Submissions: 81K+Points: 2Average Time: 10m
// You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

// Example:

// Input: 
// L = 4, R = 8 
// Output:
// 8 
// Explanation:
// 4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
// Your Task:

// Your task is to complete the function findXOR() which takes two integers l and r and returns the XOR of numbers from l to r.

// Expected Time Complexity: O(1).

// Expected Auxiliary Space: O(1).

// Constraints:

// 1<=l<=r<=109
#include<iostream>
using namespace std;
class Solution {
private:
    // Helper function to find XOR of all numbers from 0 to n
    int findXorFromZero(int n) {
        int mod = n % 4;
        if (mod == 0) return n;
        if (mod == 1) return 1;
        if (mod == 2) return n + 1;
        return 0; // if mod == 3
    }

public:
    int findXOR(int l, int r) {
        // XOR(L, R) = XOR(0, R) ^ XOR(0, L-1)
        return findXorFromZero(r) ^ findXorFromZero(l - 1);
    }
};
