// Given an integer array nums, find a that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

// Note that the product of an array with a single element is the value of that element.

 

// Example 1:

// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Example 2:

// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 

// Constraints:

//     1 <= nums.length <= 2 * 104
//     -10 <= nums[i] <= 10

class Solution {
public:
// TC -> O(N) , SC -> O(2N)
// if we know maximum product and minimum product of an subarray ending with index i-1, we can calculate for index i. the probable answers at index i is, nums[i], i*max[i-1] , i*min[i-1]
    int maxProduct(vector<int>& nums) {
        vector<int> maxUptoi (nums.size(), 0);
        vector<int> minUptoi (nums.size(), 0);
        maxUptoi[0] = nums[0]; minUptoi[0] = nums[0];
        int maxi = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int probableAns1 = nums[i] * maxUptoi[i-1];
            int probableAns2 = nums[i] * minUptoi[i-1];
            maxUptoi[i] = max(nums[i], max(probableAns1, probableAns2));
            minUptoi[i] = min(nums[i], min(probableAns1, probableAns2));
            maxi = max(maxi, maxUptoi[i]);
        } 
        return maxi;
    }
};

// How to reduce SC, we only need the previous max and min

class Solution {
public:
// TC -> O(N) 
// if we know maximum product and minimum product of an subarray ending with index i-1, we can calculate for index i. the probable answers at index i is, nums[i], i*max[i-1] , i*min[i-1]
    int maxProduct(vector<int>& nums) {
       int prevMax = nums[0]; int prevMini = nums[0];
        int maxi = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int probableAns1 = nums[i] * prevMax;
            int probableAns2 = nums[i] * prevMini;
            prevMax = max(nums[i], max(probableAns1, probableAns2));
            prevMini = min(nums[i], min(probableAns1, probableAns2));
            maxi = max(maxi, prevMax);
        } 
        return maxi;
    }
};
