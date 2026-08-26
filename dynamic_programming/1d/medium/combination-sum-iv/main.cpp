// Given an array of distinct integers nums and a target integer target, return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [1,2,3], target = 4
// Output: 7
// Explanation:
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// Note that different sequences are counted as different combinations.

// Example 2:

// Input: nums = [9], target = 3
// Output: 0

 

// Constraints:

//     1 <= nums.length <= 200
//     1 <= nums[i] <= 1000
//     All the elements of nums are unique.
//     1 <= target <= 1000

// Brute force solution
class Solution {
public:
    // number of ways we can reach target
    int solve(vector<int>& nums, int target) {
        if (target == 0) return 1; // reached the condition
        if (target < 0) return 0; // invalid state

        int no_of_ways = 0;
        // how many ways if the target can be constructed using the  elements
        for (int  i = 0; i< nums.size(); i++) {
            no_of_ways += solve(nums, target - nums[i]); // consider taking the current element
        }
        return no_of_ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums, target);
    }
};

class Solution {
public:
    //O(target × nums.size()) and SC O(N)
    // number of ways we can reach target
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        if (target == 0) return 1; // reached the condition
        if (target < 0) return 0; // invalid state
        if (dp[target] !=  -1) return dp[target];
        int no_of_ways = 0;
        // how many ways if the target can be constructed using the  elements
        for (int  i = 0; i< nums.size(); i++) {
            no_of_ways += solve(nums, target - nums[i], dp); // consider taking the current element
        }
        return dp[target] = no_of_ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp (target + 1, -1);
        return solve(nums, target, dp);
    }
};

// table up
class Solution {
public:
    // TC O(N*size) and SC O(N)
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1,  0);
        dp[0] = 1; // base case
        // dp [i]  -> number of ways to construct i
        for (int i = 1; i <= target; i++) {
            // construct dp[i] using smaller values in the table
            for (int ind = 0; ind < nums.size() ; ind++) {
                if (i - nums[ind]  < 0) continue; // not possible using this element
                
                dp[i] += dp[i - nums[ind]] ; // smaller value will be in the table before i
            }            
        }
        return (int)dp[target];
    }
};

// Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?
// for negative no, this solution will go to infinity
// to reach a target 0, nums[-2,2] -> infinite solutions are there
// so add a constraint so that each element can only taken once
