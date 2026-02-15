// 556. Next Greater Element III
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

// Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

// Example 1:

// Input: n = 12
// Output: 21
// Example 2:

// Input: n = 21
// Output: -1
 

// Constraints:

// 1 <= n <= 231 - 1
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int nextGreaterElement(int n) {
        string original=to_string(n);
        string dup=original;
        sort(dup.begin(),dup.end(),greater<char>());
        if(dup==original) return -1;
        else{
            dup=original;
            int idx=-1;
            for(int i=dup.length()-1;i>=1;i--){
                if(dup[i]>dup[i-1]){
                    idx=i;
                    break;
                }
            }
            if(idx==-1){
                reverse(dup.begin(),dup.end());
            }
            else{
                sort(dup.begin()+idx,dup.end());
                for(int i=idx;i<dup.length();i++){
                      if(dup[i]>dup[idx-1]){
                        char temp=dup[idx-1];
                        dup[idx-1]=dup[i];
                        dup[i]=temp;
                        break;
                      }
                }
            }
            long long res = stoll(dup);
            return res>INT_MAX?-1:res;
        }
    }
};