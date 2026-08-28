// Given an integer n, break it into the sum of k positive integers, where k >= 2, and maximize the product of those integers.

// Return the maximum product you can get.

 

// Example 1:

// Input: n = 2
// Output: 1
// Explanation: 2 = 1 + 1, 1 × 1 = 1.

// Example 2:

// Input: n = 10
// Output: 36
// Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.

 

// Constraints:

//     2 <= n <= 58

 
class Solution {
public:
   // TC - O(N*k) , SC - O(N)
    int integerBreak(int n) {
        vector<int> dp(n+1, 1); // state -> maximum product of positive integers that make up n; here k >= 1 not 2
        for (int i = 1; i <= n; i++) {
            int maxi = 1; 
            for (int k=1; k<=i; k++) { // generate a train of positive numbers until i
                if (i == n & k == n ) continue ;  // in this case i is original number. hence we can't use that to form i,
                // because that will always be the maximum 
                maxi = max(maxi , k * dp[i - k]);
            }
            dp[i] = maxi; // store the maximum
        }
        return dp[n];
    }
};

// cleaned up versiob
class Solution {
public:
   // TC - O(N*k) , SC - O(N)
    int integerBreak(int n) {
        vector<int> dp(n+1, 1); // state -> maximum product of positive integers that make up n; here k >= 1 not 2
        for (int i = 1; i <= n; i++) {

            for (int k=1; k< i; k+a+) { // generate a train of positive numbers until i
                // two possibilites, either don't break further or break further
                dp[i] =max(dp[i],  max(k * (i - k) , k * dp[i - k]));
            }
        }
        return dp[n];
    }
};
