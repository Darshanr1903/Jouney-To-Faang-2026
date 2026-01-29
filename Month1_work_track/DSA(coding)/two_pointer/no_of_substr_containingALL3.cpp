// 1358. Number of Substrings Containing All Three Characters
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Example 3:

// Input: s = "abc"
// Output: 1
 

// Constraints:

// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        int i=0,j=0,count=0;
        while(j<s.length()){
            mp[s[j]]++;
            while(mp.size()==3){
                count+=(s.length()-j);
                mp[s[i]]--;
                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;

            }
            j++;
        }
        return count;
    }
};
