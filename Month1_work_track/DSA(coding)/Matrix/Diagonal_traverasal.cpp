// 498. Diagonal Traverse
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

// Example 1:


// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
// Example 2:

// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// -105 <= mat[i][j] <= 105
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int count = 1;
        int size = mat.size() + mat[0].size()-1;
        int i = 0, j = 0;
        vector<int> ans;
        while (count <= size) {
            if (count % 2 != 0) {
                while (i >= 0 &&
                       j < mat[0].size()) {
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                if (j>=mat[0].size()){
                    i+=2;
                    j--;
                }
                else i=0;
                count++;
            } else {
                while ( j >= 0 && i < mat.size()) {
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                if(i>=mat.size()){
                    i--;
                    j+=2;
                }
                else j=0;
                count++;
            }
        }
        return ans;
    }
};