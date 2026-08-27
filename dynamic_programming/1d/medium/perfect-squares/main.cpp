// Given an integer n, return the least number of perfect square numbers that sum to n.

// A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

 

// Example 1:

// Input: n = 12
// Output: 3
// Explanation: 12 = 4 + 4 + 4.

// Example 2:

// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.

 

// Constraints:

//     1 <= n <= 104
// TC - O(N*k) SC - O(N)
class Solution {
public:
    int solve(int n, vector<int>& dp) {
        if (n < 0) return 0; // cannot reach n using perfect squares
        if (n == 0) return 1; //possible solution of recursion
        if (dp[n] > 0) return dp[n];
        int mini = INT_MAX;
        // generate all possible perfect square under n and try form
        // a solution
        for (int i = 1;i <= n; i++ ) {
            long long squared = i*i;
            if ( squared > n) break ; // out of sample space
            int choose_square = solve(n - squared, dp) + 1;

            mini = min(mini, choose_square);
        }
        return dp[n] = mini; // there will always be a solution because 1 is a perfecrt square
    }
    int numSquares(int n) {
        vector<int> dp(n + 1 , -1);
        return solve(n, dp) - 1;
    }
};
