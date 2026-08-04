// Given an integer array nums, return the length of the longest strictly increasing .

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4

// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

 

// Constraints:

//     1 <= nums.length <= 2500
//     -104 <= nums[i] <= 104

 

// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?



// SOlution of SC O(N) and 
// TC -> there are n unique states  and for each n we have to do n - 1 state so basially O(N^2)
class Solution {
public:
    int solve(vector<int>& nums, int ind, vector<int>& dp) {
       if (ind == nums.size())  return dp[ind] = 1; // base condition, reached the boundary
       if (ind > nums.size() ) return 0; 
       if (dp[ind] > 0) return dp[ind];

        // for each and every entry point, 
        // run iteration for a entry greater and then solve recursively
        int maxi = 1;   
        for(int i = ind+1; i < nums.size(); i++ ) {
            if (nums[i] > nums[ind]) {
                maxi = max(maxi , solve(nums, i, dp) +1 );
            }
        }
        return dp[ind]= maxi;
    } 
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp (nums.size() + 1, -1);
        int maxi = 1;
        // iterate through possible entry points
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, solve(nums, i, dp));
        }
        return maxi;
    }
};


// tabulation , still same complexity
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp (nums.size(), -1);
        dp[nums.size() - 1] = 1; // last element
        int result = 1;
        // start from the end and go backwards
        for (int i = nums.size() - 1; i >= 0; i--) {
            int maxi = 1;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    maxi = max(maxi, 1 + dp[j]); // if we found a greater element, solution is 1 + [ solution of greater]
                }
            }
            dp[i] = maxi;
            result = max(result, maxi);
        }
        return result;
    }
};
