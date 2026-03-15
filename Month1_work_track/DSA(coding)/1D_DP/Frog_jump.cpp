// 403. Frog Jump
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

// Given a list of stones positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

// If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

 

// Example 1:

// Input: stones = [0,1,3,5,6,8,12,17]
// Output: true
// Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.
// Example 2:

// Input: stones = [0,1,2,3,4,8,9,11]
// Output: false
// Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.
 

// Constraints:

// 2 <= stones.length <= 2000
// 0 <= stones[i] <= 231 - 1
// stones[0] == 0
// stones is sorted in a strictly increasing order.
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

class Solution {
    // memo[index][last_jump]
    // Using short to save memory; -1: unvisited, 0: false, 1: true
    signed char memo[2001][2001];
    unordered_map<int, int> val_to_idx;

public:
    bool solve(vector<int>& stones, int i, int k) {
        if (i == stones.size() - 1) return true;
        if (memo[i][k] != -1) return memo[i][k];

        // Try three possible jumps: k-1, k, k+1
        for (int next_k = k - 1; next_k <= k + 1; next_k++) {
            if (next_k <= 0) continue; // Must move forward

            int next_val = stones[i] + next_k;
            
            // Check if a stone exists at the landing position
            if (val_to_idx.count(next_val)) {
                if (solve(stones, val_to_idx[next_val], next_k)) {
                    return memo[i][k] = 1;
                }
            }
        }

        return memo[i][k] = 0;
    }

    bool canCross(vector<int>& stones) {
        // Initialization
        int n = stones.size();
        if (stones[1] != 1) return false; // First jump must be 1 unit
        
        memset(memo, -1, sizeof(memo));
        val_to_idx.clear();
        for (int i = 0; i < n; i++) val_to_idx[stones[i]] = i;

        // Start from index 1, with the last jump being 1
        return solve(stones, 1, 1);
    }
};