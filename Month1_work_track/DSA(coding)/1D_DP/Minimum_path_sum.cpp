// 64. Minimum Path Sum
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 

// Example 1:


// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Example 2:

// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 200
// 0 <= grid[i][j] <= 200
#include<iostream>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        //vector<vector<int>>dp(m,vector<int>(n,0));
        vector<int>prev(n,0);
        for(int i=0;i<m;i++){
            vector<int>temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0&&j==0) temp[j]=grid[i][j];
                else{
                    int left=INT_MAX;
                    int up=INT_MAX;
                    if(j-1>=0) left=temp[j-1];
                    if(i-1>=0) up=prev[j];
                    temp[j]=grid[i][j]+min(left,up);
                }
            }
            prev=temp;
        }
        return prev[n-1];
    }
};
