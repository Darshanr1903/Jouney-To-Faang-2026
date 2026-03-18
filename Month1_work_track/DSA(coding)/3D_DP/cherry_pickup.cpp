// 741. Cherry Pickup
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

// 0 means the cell is empty, so you can pass through,
// 1 means the cell contains a cherry that you can pick up and pass through, or
// -1 means the cell contains a thorn that blocks your way.
// Return the maximum number of cherries you can collect by following the rules below:

// Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
// After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
// When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
// If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
 

// Example 1:


// Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
// Output: 5
// Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
// 4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
// Then, the player went left, up, up, left to return home, picking up one more cherry.
// The total number of cherries picked up is 5, and this is the maximum possible.
// Example 2:

// Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
// Output: 0
 

// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 50
// grid[i][j] is -1, 0, or 1.
// grid[0][0] != -1
// grid[n - 1][n - 1] != -1
#include<iostream>
using namespace std;
class Solution {
    // 3D Memoization table: max grid size is 50, so 50x50x50 is safe
    int memo[50][50][50];

public:
    int cherry_picker(vector<vector<int>>& grid, int i1, int j1, int i2) {
        // Calculate j2 on the fly based on the simultaneous steps equation
        int j2 = i1 + j1 - i2;
        int n = grid.size();

        // 1. Out of bounds check
        if (i1 >= n || i2 >= n || j1 >= n || j2 >= n) return -1e9; 
        
        // 2. Thorn check
        if (grid[i1][j1] == -1 || grid[i2][j2] == -1) return -1e9;
        
        // 3. Destination check (both arrive at the same time)
        if (i1 == n - 1 && j1 == n - 1) return grid[i1][j1];
        
        // 4. Memoization check
        if (memo[i1][j1][i2] != -1) return memo[i1][j1][i2];

        // 5. Cherry counting logic (Your exact logic!)
        int current_cherries;
        if (i1 == i2 && j1 == j2) {
            current_cherries = grid[i1][j1];
        } else {
            current_cherries = grid[i1][j1] + grid[i2][j2];
        }

        // 6. Branching (Renamed to match actual directions)
        int right_right = cherry_picker(grid, i1, j1 + 1, i2);
        int right_down  = cherry_picker(grid, i1, j1 + 1, i2 + 1);
        int down_down   = cherry_picker(grid, i1 + 1, j1, i2 + 1);
        int down_right  = cherry_picker(grid, i1 + 1, j1, i2);

        // Find the absolute best path combination
        int max_next = max({right_right, right_down, down_down, down_right});

        // Save to cache and return
        return memo[i1][j1][i2] = current_cherries + max_next;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        // Initialize the 3D memo table with -1
        memset(memo, -1, sizeof(memo));
        
        int ans = cherry_picker(grid, 0, 0, 0);
        
        // If the answer is highly negative, no valid path was found
        if (ans < 0) return 0;
        return ans;
    }
};
