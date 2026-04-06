// 764. Largest Plus Sign
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// You are given an integer n. You have an n x n binary grid grid with all values initially 1's except for some indices given in the array mines. The ith element of the array mines is defined as mines[i] = [xi, yi] where grid[xi][yi] == 0.

// Return the order of the largest axis-aligned plus sign of 1's contained in grid. If there is none, return 0.

// An axis-aligned plus sign of 1's of order k has some center grid[r][c] == 1 along with four arms of length k - 1 going up, down, left, and right, and made of 1's. Note that there could be 0's or 1's beyond the arms of the plus sign, only the relevant area of the plus sign is checked for 1's.

 

// Example 1:


// Input: n = 5, mines = [[4,2]]
// Output: 2
// Explanation: In the above grid, the largest plus sign can only be of order 2. One of them is shown.
// Example 2:


// Input: n = 1, mines = [[0,0]]
// Output: 0
// Explanation: There is no plus sign, so return 0.
 

// Constraints:

// 1 <= n <= 500
// 1 <= mines.length <= 5000
// 0 <= xi, yi < n
// All the pairs (xi, yi) are unique.
#include<iostream>
using namespace std;
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>mat;
        mat.resize(n,vector<int>(n,1));
        for(int i=0;i<mines.size();i++){
            mat[mines[i][0]][mines[i][1]]=0;
        }
        vector<vector<int>>left,right,top,bottom;
        left=right=top=bottom=mat;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=n-1-i;
                int y=n-1-j;
                if(i>0&&top[i][j]) top[i][j]+=top[i-1][j];
                if(j>0&&left[i][j]) left[i][j]+=left[i][j-1];
                if(y<n-1&&right[x][y]) right[x][y]+=right[x][y+1];
                if(x<n-1&&bottom[x][y]) bottom[x][y]+=bottom[x+1][y];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,min({left[i][j],right[i][j],top[i][j],bottom[i][j]}));
            }
        }
        return ans;
    }
};