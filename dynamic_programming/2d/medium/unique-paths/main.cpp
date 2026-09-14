// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or equal to 2 * 109.
class Solution {
public:
    // TC -> O(2^m+n) -> recursion depth
    int find_ways(int i, int j, int m, int  n) {
        if (i == m-1 && j == n-1) { // reached the finish, return 1
            return 1;
        }
        if (i >= m || j >= n) {// out of boundary
            return 0;
        }
        // go right and go down
        return find_ways(i+1, j, m, n) + find_ways(i, j+1, m, n);
    }
    int uniquePaths(int m, int n) {
        return find_ways(0, 0, m, n);
    }
};

class Solution {
public:
    // TC -> O(m*n) 
    // SC - O(m+n)
    int find_ways(int i, int j, int m, int  n, vector<vector<int>>& dp) {
        if (i == m-1 && j == n-1) { // reached the finish, return 1
            return 1;
        }
        if (i >= m || j >= n) {// out of boundary
            return 0;
        }
        if (dp[i][j] >= 0) return dp[i][j];
        // go right and go down
        return dp[i][j] = find_ways(i+1, j, m, n, dp) + find_ways(i, j+1, m, n, dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int> (n , -1));
        return find_ways(0, 0, m, n, dp);
    }
};

// bottom up
class Solution {
public:
    // TC -> O(m*n) 
    // SC - O(m*n)
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int> (n , 0));
        dp[m-1][n-1] = 1;   
        for (int i = m-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j --) {
                if (i == m-1 && j== n-1) continue;
                if (i + 1 < m ) dp[i][j] += dp[i+1][j];
                if (j + 1 < n ) dp[i][j] += dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
