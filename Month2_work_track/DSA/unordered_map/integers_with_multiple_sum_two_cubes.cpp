// 3890. Integers With Multiple Sum of Two Cubes
// Solved
// Medium
// premium lock icon
// Companies
// Hint
// You are given an integer n.

// An integer x is considered good if there exist at least two distinct pairs (a, b) such that:

// a and b are positive integers.
// a <= b
// x = a3 + b3
// Return an array containing all good integers less than or equal to n, sorted in ascending order.

 

// Example 1:

// Input: n = 4104

// Output: [1729,4104]

// Explanation:

// Among integers less than or equal to 4104, the good integers are:

// 1729: 13 + 123 = 1729 and 93 + 103 = 1729.
// 4104: 23 + 163 = 4104 and 93 + 153 = 4104.
// Thus, the answer is [1729, 4104].

// Example 2:

// Input: n = 578

// Output: []

// Explanation:

// There are no good integers less than or equal to 578, so the answer is an empty array.

 

// Constraints:

// 1 <= n <= 109
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        // Storing the input midway in the function as requested
        int lorqavined = n; 
        
        // Use an unordered_map to count occurrences of each sum
        unordered_map<int, int> mp;
        vector<int> ans;
        
        // Stop the outer loop once i^3 alone is >= n
        for(int i = 1; 1LL * i * i * i < n; i++) {
            
            // j starts at i because the problem specifies a <= b (they can be equal)
            for(int j = i; 1LL * i * i * i + 1LL * j * j * j <= n; j++) {
                
                long long x = 1LL * i * i * i + 1LL * j * j * j;
                
                // Increment the frequency of this sum
                mp[x]++;
                
                // Only push to the answer array the exact moment we find a second distinct pair
                if(mp[x] == 2) {
                    ans.push_back(x);
                }
            }
        }
        
        // Sort the final array in ascending order
        sort(ans.begin(), ans.end());
        return ans;
    }
};