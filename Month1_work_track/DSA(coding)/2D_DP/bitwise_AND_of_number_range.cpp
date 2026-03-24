// 201. Bitwise AND of Numbers Range
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.

 

// Example 1:

// Input: left = 5, right = 7
// Output: 4
// Example 2:

// Input: left = 0, right = 0
// Output: 0
// Example 3:

// Input: left = 1, right = 2147483647
// Output: 0
 

// Constraints:

// 0 <= left <= right <= 231 - 1
#include<iostream>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        
        for(int bit_index = 0; bit_index < 32; bit_index++){
            // Use 1LL to safely shift up to the 31st bit
            if((left & (1LL << bit_index))){
                
                // Use long long so 1LL << 32 doesn't overflow
                long long number = 1LL << (bit_index + 1);
                long long remainder = (long long)left % number;
                
                // Cast right to long long to be completely safe during subtraction
                if((long long)right - left < (number - remainder)){
                    ans = ans | (1LL << bit_index);
                }
            }
        }
        
        return ans;
    }
};