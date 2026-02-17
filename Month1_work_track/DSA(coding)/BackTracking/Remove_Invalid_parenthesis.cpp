// 301. Remove Invalid Parentheses
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

// Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

 

// Example 1:

// Input: s = "()())()"
// Output: ["(())()","()()()"]
// Example 2:

// Input: s = "(a)())()"
// Output: ["(a())()","(a)()()"]
// Example 3:

// Input: s = ")("
// Output: [""]
 

// Constraints:

// 1 <= s.length <= 25
// s consists of lowercase English letters and parentheses '(' and ')'.
// There will be at most 20 parentheses in s.
#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    vector<string> ans;
    int length = 0;
    unordered_set<string> st;

    void helper(string& s, int idx, string& dup, int track) {
        if (track < 0) return;

        // Base Case: Reached the end of the string
        if (idx == s.length()) {
            if (track == 0 && dup.length() == length) {
                if (st.find(dup) == st.end()) {
                    ans.push_back(dup);
                    st.insert(dup);
                }
            }
            return;
        }

        char current = s[idx];

        if (current != '(' && current != ')') {
            // It's a letter: We must keep it
            dup += current;
            helper(s, idx + 1, dup, track);
            dup.pop_back(); // Backtrack
        } else {
            // Option 1: Keep the parenthesis
            dup += current;
            helper(s, idx + 1, dup, (current == '(' ? track + 1 : track - 1));
            dup.pop_back(); 

            // Option 2: Remove the parenthesis
            helper(s, idx + 1, dup, track);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        ans.clear();
        st.clear();
        string dup = "";
        
        // Correct logic to find the maximum possible length of a valid string
        int left_rem = 0, right_rem = 0;
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) left_rem--;
                else right_rem++;
            }
        }
        
        length = s.length() - (left_rem + right_rem);

        helper(s, 0, dup, 0);
        
        if (ans.empty()) return {""};
        
        return ans;
    }
};