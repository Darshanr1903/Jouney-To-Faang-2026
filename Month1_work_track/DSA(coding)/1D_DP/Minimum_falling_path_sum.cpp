// 931. Minimum Falling Path Sum
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

// Example 1:


// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.
// Example 2:


// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.
 

// Constraints:

// n == matrix.length == matrix[i].length
// 1 <= n <= 100
// -100 <= matrix[i][j] <= 100
#include<iostream>
using namespace std;
class Solution {
public:
vector<vector<int>>dp;
int falling_path(vector<vector<int>>& matrix,int i,int j){
    if(j>=matrix[0].size()||j<0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==matrix.size()-1) return dp[i][j]=matrix[i][j];
    int left=falling_path(matrix,i+1,j-1);
    int down=falling_path(matrix,i+1,j);
    int right=falling_path(matrix,i+1,j+1);
    return dp[i][j]=matrix[i][j]+min({left,right,down});
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int ans=INT_MAX;
        int m=matrix.size();
        int n=matrix[0].size();
        //dp.resize(m,vector<int>(n,-1));
        vector<int>prev(n,0);
        for(int j=0;j<matrix[0].size();j++){
            prev[j]=matrix[m-1][j];
        }
        for(int i=m-2;i>=0;i--){
            vector<int>temp(n,0);
            for(int j=n-1;j>=0;j--){
                int left=INT_MAX;
                int down=prev[j];
                int right=INT_MAX;
                if(j-1>=0) left=prev[j-1];
                if(j+1<n) right=prev[j+1];
                temp[j]=matrix[i][j]+min({left,right,down});
            }
            prev=temp;
        }
        for(int j=0;j<matrix[0].size();j++){
            ans=min(ans,prev[j]);
        }
        return ans;
    }
};