// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 

// Example 1:

// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// Example 2:

// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

 

// Constraints:

//     1 <= nums.length <= 200
//     1 <= nums[i] <= 100

// Brute force solution
class Solution {
public:
    // O(2^n) TC, every level has two options
    bool solve(vector<int>& nums, int ind, int target) {
        if (target == 0) return true; // achieved the target
        if (target < 0 || ind  >= nums.size()) return false; // out of boundary

        // two cases, either take current index and recurse or don't take
        return solve(nums, ind+1, target - nums[ind]) || solve(nums, ind+1, target);
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(int i=0; i< nums.size(); i++) {
            total_sum += nums[i];
        }
        if (total_sum  % 2 != 0) {
            // sum is odd, no way to partition
            return false;
        }
        return solve(nums, 0, total_sum/2); // find a subset with sum equal to total_sum/2;
    }
};

// 2D Dp solution with O(N*target) TC and O(target) sc Memoization
class Solution {
public:
    // O(N * target) COmplexity, SC - O(target)
    int solve(vector<int>& nums, int ind, int target, vector<vector<int>>& dp) {
        if (target == 0) return 1; // achieved the target
        if (target < 0 || ind  >= nums.size()) return 0; // out of boundary
        if (dp[ind][target] >= 0) return dp[ind][target];
        // two cases, either take current index and recurse or don't take
        if (solve(nums, ind+1, target - nums[ind], dp) || solve(nums, ind+1, target, dp)) {
            return dp[ind ][target] = 1;
        }
        return dp[ind][target] = 0; // not possible
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(int i=0; i< nums.size(); i++) {
            total_sum += nums[i];
        }
        if (total_sum  % 2 != 0) {
            // sum is odd, no way to partition
            return false;
        }
         // three states required for dp, -1 -> not computed, 0 ->false, 1 -> true
        vector<vector<int>> dp (nums.size(), vector<int> ((total_sum/2) + 1, -1));
        if (solve(nums, 0, total_sum/2, dp) == 1) {
            return true;
        }
        return false;
    }
};

// set approach, store every possible subset sum and start backwards
// TC - O(n*sum) SC O(SUm)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        // store the all possible subset sums in a set
        // start from the end
        unordered_set<int> dp;
        dp.insert(0);
        int target = sum / 2;
        for (int i=nums.size()-1; i >= 0 ; i--) {
            unordered_set<int> nextDP;
            for (int t: dp) {
                // goo throuh every sum in set currently
                if (t + nums[i] == target) {
                    return true;
                }
                nextDP.insert(t + nums[i]); // insert the sum we seen
                nextDP.insert(t); // insert the case we are not taking i
            }
             dp = nextDP;
        }
         return false;
    }
};
