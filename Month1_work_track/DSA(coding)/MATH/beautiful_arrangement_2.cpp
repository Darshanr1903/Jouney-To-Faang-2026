// 667. Beautiful Arrangement II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given two integers n and k, construct a list answer that contains n different positive integers ranging from 1 to n and obeys the following requirement:

// Suppose this list is answer = [a1, a2, a3, ... , an], then the list [|a1 - a2|, |a2 - a3|, |a3 - a4|, ... , |an-1 - an|] has exactly k distinct integers.
// Return the list answer. If there multiple valid answers, return any of them.

 

// Example 1:

// Input: n = 3, k = 1
// Output: [1,2,3]
// Explanation: The [1,2,3] has three different positive integers ranging from 1 to 3, and the [1,1] has exactly 1 distinct integer: 1
// Example 2:

// Input: n = 3, k = 2
// Output: [1,3,2]
// Explanation: The [1,3,2] has three different positive integers ranging from 1 to 3, and the [2,1] has exactly 2 distinct integers: 1 and 2.
 

// Constraints:

// 1 <= k < n <= 104
#include<iostream>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        unordered_set<int>s;
        vector<int>v;
        v.push_back(1);
        s.insert(1);
        int count=2;
        while(v.size()<n){
           if(n-v.size()>k){
            v.push_back(count);
            s.insert(count);
            count++;
           }
           else{
            int x=v[v.size()-1];
            if(x+k<=n&&s.find(abs(x+k))==s.end()){
               v.push_back(abs(x+k));
               s.insert(abs(x+k));
               k--;
            }
            else{
                v.push_back(abs(x-k));
                s.insert(abs(x-k));
                k--;
            }
           }
        }
        return v;
    }
};