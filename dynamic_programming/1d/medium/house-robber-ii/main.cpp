// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

// Example 2:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 3:

// Input: nums = [1,2,3]
// Output: 3

class Solution {
public:
    int solve(int i, vector<int>& nums, int n, vector<int>& dp) {
        if (i>= n) return 0; // reached the end
        if(dp[i] >= 0) return dp[i];
        int rob_current = nums[i] + solve(i+2, nums, n,dp);
        int jump_next = solve(i+1, nums, n,dp);
        return dp[i] = max(rob_current, jump_next);
    }

// TC - O(N) + SC - O(2N)

    int rob(vector<int>& nums) {
        int totalHouses = nums.size();
        if (totalHouses == 1) return nums[0];
        vector<int> dpForFirstHouse(nums.size(), -1);
        vector<int> dpForSecondHouse(nums.size(), -1);
        int considerRobbingFirstHouse = solve(0, nums, totalHouses-1, dpForFirstHouse);
        int skipFirstHouse = solve(1, nums, totalHouses, dpForSecondHouse);
        return max(considerRobbingFirstHouse, skipFirstHouse);    
    }
};
