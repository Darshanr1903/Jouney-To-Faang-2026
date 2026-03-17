// 120. Triangle
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
// Example 2:

// Input: triangle = [[-10]]
// Output: -10
 

// Constraints:

// 1 <= triangle.length <= 200
// triangle[0].length == 1
// triangle[i].length == triangle[i - 1].length + 1
// -104 <= triangle[i][j] <= 104
 

// Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
#include<iostream>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        //vector<vector<int>> dp;
        //dp.resize(m, vector<int>(m, 0)); 
        vector<int>prev(m,0);
        // Base case: Set the bottom row of the dp table to the bottom row of the triangle
        for (int j = 0; j < m; j++) {
            prev[j] = triangle[m-1][j];
        }
        
        // Build the table from the second-to-last row up to the top
        for (int i = m - 2; i >= 0; i--) {
            // A row `i` in the triangle has `i + 1` elements
            vector<int>temp(m,0);
            for (int j = 0; j <= i; j++) {
                
                // Fetching the pre-calculated values from the row directly below
                int verticaly_down = prev[j];
                int diagonaly_down = prev[j+1];
                
                // Calculate the minimum sum for the current cell
                temp[j] = triangle[i][j] + min(verticaly_down, diagonaly_down);
            }
            prev=temp;
        }
        
        // The top element now contains the minimum path sum
        return prev[0];
    }
};