// 85. Maximal Rectangle
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

 

// Example 1:


// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 6
// Explanation: The maximal rectangle is shown in the above picture.
// Example 2:

// Input: matrix = [["0"]]
// Output: 0
// Example 3:

// Input: matrix = [["1"]]
// Output: 1
 

// Constraints:

// rows == matrix.length
// cols == matrix[i].length
// 1 <= rows, cols <= 200
// matrix[i][j] is '0' or '1'.
#include <vector>
#include <stack>
#include <algorithm>
#include<iostream>

using namespace std;
class Solution {
public:
int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int max_ans = 0;

        for (int i = 0; i < n; i++) {
            // Logic Fix 1: Pop when the current bar is SMALLER than the stack top.
            // This maintains a strictly increasing stack to find the NSE.
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                int nse_index = i;
                int top = st.top(); // top is the index of the bar
                st.pop();
                
                int pse_index = -1;
                if (!st.empty()) pse_index = st.top();
                
                // Logic Fix 2: Area must be (Width * Height). 
                // Height is nums[top], not top (which is an index).
                max_ans = max(max_ans, (nse_index - pse_index - 1) * nums[top]);
            }
            st.push(i);
        }

        // Processing remaining elements in the stack
        int nse_index = n;
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            
            int pse_index = -1;
            if (!st.empty()) pse_index = st.top();
            
            // Logic Fix 3: Use nums[top] for height here as well.
            max_ans = max(max_ans, (nse_index - pse_index - 1) * nums[top]);
        }

        return max_ans;
}
    int maximalRectangle(vector<vector<char>>& matrix) {
        int col=matrix[0].size();
        int row=matrix.size();
        vector<vector<int>>matrix1(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]=='1') matrix1[i][j]=1;
            }
        }
        for(int j=0;j<col;j++){
            for(int i=1;i<row;i++){
                if(matrix1[i][j]!=0){
                    matrix1[i][j]+=matrix1[i-1][j];
                }
            }
        }
        int max_ans=0;
        for(int i=0;i<row;i++){
            max_ans=max(max_ans,largestRectangleArea(matrix1[i]));
        }
        return max_ans;
    }
};
