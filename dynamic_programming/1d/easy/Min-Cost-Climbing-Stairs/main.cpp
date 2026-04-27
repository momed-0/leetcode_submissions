// https://leetcode.com/problems/min-cost-climbing-stairs
//https://neetcode.io/solutions/min-cost-climbing-stairs
// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor.

 

// Example 1:

// Input: cost = [10,15,20]
// Output: 15
// Explanation: You will start at index 1.
// - Pay 15 and climb two steps to reach the top.
// The total cost is 15.

// Example 2:

// Input: cost = [1,100,1,1,1,100,1,1,100,1]
// Output: 6
// Explanation: You will start at index 0.
// - Pay 1 and climb two steps to reach index 2.
// - Pay 1 and climb two steps to reach index 4.
// - Pay 1 and climb two steps to reach index 6.
// - Pay 1 and climb one step to reach index 7.
// - Pay 1 and climb two steps to reach index 9.
// - Pay 1 and climb one step to reach the top.
// The total cost is 6.

 

// Constraints:

//     2 <= cost.length <= 1000
//     0 <= cost[i] <= 999

// inefficient -> not saving the solutions
class Solution {
public:
    int solve(int i, int n, vector<int>& cost) {
        if (i >= n) return 0;
        return  cost[i] + min(solve(i+1, n, cost), solve(i+2, n, cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        return  min(solve(0, n, cost), solve(1, n, cost));
    }
};

class Solution {
public:
    int solve(int i, int n, vector<int>& cost,  vector<int>& cache) {
        if (i >= n) return 0;
        if(cache[i] >= 0) return cache[i];
        return  cache[i] = cost[i] + min(solve(i+1, n, cost, cache), solve(i+2, n, cost, cache));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int> cache(n, -1);
        return  min(solve(0, n, cost,cache), solve(1, n, cost,cache));
    }
};
