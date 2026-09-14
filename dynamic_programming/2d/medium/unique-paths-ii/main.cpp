// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

// Example 1:

// Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Example 2:

// Input: obstacleGrid = [[0,1],[0,0]]
// Output: 1

 

// Constraints:

//     m == obstacleGrid.length
//     n == obstacleGrid[i].length
//     1 <= m, n <= 100
//     obstacleGrid[i][j] is 0 or 1.

class Solution {
public:
   // TC - O(m*n)
   // SC - O(m+n)
    int find_no_ways(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j, vector<vector<int>>& dp) {
        if (i == m-1 && j == n-1) return 1; // reached the finish
        if (dp[i][j] >= 0) return dp[i][j];

        int unique_ways = 0;
        if (i + 1 < m && obstacleGrid[i+1][j] == 0) { // free space
            unique_ways += find_no_ways(obstacleGrid, m, n, i+1, j, dp); // go right
        }
        if (j + 1 < n && obstacleGrid[i][j+1] == 0) {
            unique_ways += find_no_ways(obstacleGrid, m, n, i, j + 1, dp); // go down
        }
        return dp[i][j] = unique_ways;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 ) return 0;
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return find_no_ways(obstacleGrid, m, n, 0,0, dp);
    }
};

class Solution {
public:
   // TC - O(m*n)
   // SC - O(m+n)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1  || obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<long long >> dp(m, vector<long long> (n, 0));
        dp[m-1][n-1] = 1;
        for (int i = m-1; i >=0; i--) {
            for (int j= n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) continue;

                if (i +1 < m && obstacleGrid[i+1][j] == 0) dp[i][j] += dp[i+1][j];
                if (j +1 < n && obstacleGrid[i][j+1] == 0) dp[i][j] += dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
   // TC - O(m*n)
   // SC - O(n)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
       vector<uint> dp(n +1, 0);
        dp[n - 1] = 1;
        for (int i = m-1; i >=0; i--) {
            for (int j= n-1; j >= 0; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else {
                    // here dp[j] is answer for previous row, that is below
                    // prv iteration calculated dp[j+1] ( since we are starting from end)
                    // so that is right;
                    dp[j] += dp[j+1]; // below + right // dp[j] is below , dp[j+1] right
                }
            }
        }
        return dp[0];
    }
};
