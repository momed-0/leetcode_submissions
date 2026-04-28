// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.

 

// Constraints:

//     1 <= nums.length <= 100
//     0 <= nums[i] <= 400

class Solution {
public:
    int solve(int i, vector<int>& nums, int n, vector<int>& dp) {
        if (i>= n) return 0; // reached the end
        if(dp[i] >= 0) return dp[i];
        int rob_current = nums[i] + solve(i+2, nums, n,dp);
        int jump_next = solve(i+1, nums, n,dp);
        return dp[i] = max(rob_current, jump_next);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, nums.size(), dp);
    }
};

