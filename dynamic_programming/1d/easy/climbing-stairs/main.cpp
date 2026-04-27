// https://leetcode.com/problems/climbing-stairs/
// https://neetcode.io/solutions/climbing-stairs

// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

// Example 1:

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Example 2:

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

 

// Constraints:

//     1 <= n <= 45



// inefficient , we can save the subproblem solutions
// class Solution {
// public:
//     int solve(int i, int n) {
//         if(i > n) return 0; // not valid
//         if (i == n) return 1; // solved the problem
//         return solve(i+1, n) + solve(i + 2, n); // go both ways to solve the problem
//     }
//     int climbStairs(int n) {
//         return solve(1, n) + solve(2, n); // two choices at all time
//     }
// };

class Solution {
public:
    int solve(int i, int n,  vector<int>& dp) {
        if(i > n) return 0; // not valid
        if (i == n) return 1; // solved the problem
        if (dp[i] >= 0) return  dp[i]; // try to see in memory
        return dp[i] = solve(i+1, n,dp ) + solve(i + 2, n, dp); // go both ways to solve the problem
    }
    int climbStairs(int n) {
       vector<int>  dp(n+1,-1);
        return solve(1, n, dp) + solve(2, n,  dp); // two choices at all time
    }
};
