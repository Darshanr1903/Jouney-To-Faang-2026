// 402. Remove K Digits
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

// Constraints:

// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty()&&k>0&&(st.top()-'0')>(num[i]-'0')){
                  st.pop();
                  k--;
            }
            st.push(num[i]);
        }
        string ans="";
        while(st.size()){
            if(k==0) ans+=st.top();
            else k--;
            st.pop();
        }
        if(ans.empty()) return "0";
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.size()-1&&ans[i]=='0') i++;
        ans=ans.substr(i,ans.length()-i);
        return ans;
    }
};