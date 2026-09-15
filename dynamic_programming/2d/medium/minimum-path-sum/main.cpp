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

//     m == grid.length
//     n == grid[i].length
//     1 <= m, n <= 200
//     0 <= grid[i][j] <= 200

 
 class Solution {
public:
    // TC -O(M*N)
    // SC - O(M*N)
    int solve(vector<vector<int>>& grid, int m,int n, int i, int j, vector<vector<int>>& dp) {
        if (i == m-1 && j == n-1) return grid[i][j]; // base case
        if (dp[i][j] >= 0) return dp[i][j];

        int go_down = INT_MAX; int go_right = INT_MAX;
        if (i + 1 < m) go_down = solve(grid, m, n, i+1, j, dp) + grid[i][j];
        if (j + 1 < n) go_right = solve(grid, m, n, i, j+1, dp)  + grid[i][j];
        return dp[i][j] = min(go_down, go_right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(grid, m , n, 0, 0, dp);
    }
};

// Tabulation method
class Solution {
public:
    // TC -O(M*N)
    // SC - O(M*N)
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, 0));
        dp[m-1][n-1] = grid[m-1][n-1];
        
        for (int i = m-1; i >= 0; i--) {
            for (int j= n-1; j>=0; j--) {
                if (i == m-1 && j == n-1) continue;

                int go_down = INT_MAX; int go_right = INT_MAX;
                if (i + 1 < m) go_down = dp[i+1][j];
                if (j + 1 < n) go_right = dp[i][j+1];
                
                dp[i][j] = min(go_down, go_right) + grid[i][j];
            }
        }
        return dp[0][0];
    }
};
