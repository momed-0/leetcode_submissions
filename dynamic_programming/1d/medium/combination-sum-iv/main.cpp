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

 class Solution {
public:
//TC - O(2^n) solution and O(1) space
    int solve(int ind, int target, vector<int>& nums) {
        if (target == 0) return 1; // base case condition
        if (ind >= nums.size() || target < 0) return 0 ; // invalid state

        int take_i_start = solve(0, target - nums[ind], nums);
        int not_take_i_move = solve(ind+1, target, nums);
        return take_i_start + not_take_i_move; 
    }
    int combinationSum4(vector<int>& nums, int target) {
        return solve(0, target, nums);
    }
};



// Follow up: What if negative numbers are allowed in the given array? How does it change the problem? What limitation we need to add to the question to allow negative numbers?
