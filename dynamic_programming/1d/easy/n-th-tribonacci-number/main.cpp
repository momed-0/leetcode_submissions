// The Tribonacci sequence Tn is defined as follows: 

// T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

// Given n, return the value of Tn.

 

// Example 1:

// Input: n = 4
// Output: 4
// Explanation:
// T_3 = 0 + 1 + 1 = 2
// T_4 = 1 + 1 + 2 = 4

// Example 2:

// Input: n = 25
// Output: 1389537

 

// Constraints:

//     0 <= n <= 37

// basically f(x) = f(x-1) + f(x-3) + f(x-3) for x > 2

class Solution {
public:
    int solve(int i, vector<int>& dp) {
        if(dp[i] >= 0 ) return dp[i]; 
        return dp[i] = solve(i-1, dp) + solve(i-2, dp) + solve(i-3, dp);
    }
    int tribonacci(int n) {
        if(n <=2 ) {
            if (n == 1 || n == 2) return 1;
            return 0; 
        }
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        return solve(n, dp);
    }
};

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+3, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i =3 ; i<=n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
};



