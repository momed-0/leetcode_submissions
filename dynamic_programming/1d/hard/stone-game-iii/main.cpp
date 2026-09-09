// 1406. Stone Game III
// Attempted
// Hard
// Topics
// premium lock iconCompanies
// Hint

// Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

// Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

// The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

// The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

// Assume Alice and Bob play optimally.

// Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

 

// Example 1:

// Input: stoneValue = [1,2,3,7]
// Output: "Bob"
// Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.

// Example 2:

// Input: stoneValue = [1,2,3,-9]
// Output: "Alice"
// Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
// If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
// If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
// Remember that both play optimally so here Alice will choose the scenario that makes her win.

// Example 3:

// Input: stoneValue = [1,2,3,6]
// Output: "Tie"
// Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.

 

// Constraints:

//     1 <= stoneValue.length <= 5 * 104
//     -1000 <= stoneValue[i] <= 1000

// messy brute force solution
class Solution {
public:
    // diff -> alice's total scores - bob's total scores
    // minmax, alice try to maximise the difference while bob try to minimize the difference
    int solve(vector<int>& stoneValue, int ind, string player, int diff) {
        int n = stoneValue.size();
        if (ind >= n ) return diff;
        if (player == "Alice") {
            int take1 = INT_MIN, take2 = INT_MIN, take3 = INT_MIN;
            if (ind + 2 < n) {
                take3 = solve(stoneValue, ind+3, "Bob", diff + stoneValue[ind] + stoneValue[ind+1] + stoneValue[ind+2]);
            }
            if (ind +1 < n) {
                take2 = solve(stoneValue, ind+2, "Bob", diff + stoneValue[ind] + stoneValue[ind+1]);
            }
            take1 = solve(stoneValue, ind+1, "Bob", diff + stoneValue[ind]);
            return max(take1, max(take2, take3));
        }

        if (player == "Bob") {
            int take1 = INT_MAX, take2 = INT_MAX, take3 = INT_MAX;
            if (ind + 2 < n) {
                take3 = solve(stoneValue, ind+3, "Alice", diff - stoneValue[ind] - stoneValue[ind+1] - stoneValue[ind+2]);
            }
            if (ind +1 < n) {
                take2 = solve(stoneValue, ind+2, "Alice", diff - stoneValue[ind] - stoneValue[ind+1]);
            }
            take1 = solve(stoneValue, ind+1,  "Alice", diff - stoneValue[ind]);
            return min(take1, min(take2, take3));
        }
        return diff;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int diff = solve(stoneValue, 0,"Alice", 0);
        if (diff == 0) return "Tie";
        if (diff > 0) return "Alice";
        else return "Bob";
    }
};

class Solution {
public:
 //O(N) both TC and SC
    // advantage that the current player has it at ind 
    // each t=player have to maximise the advantage
    int solve(vector<int>& nums, int n, int ind, vector<int>& dp) {
       if (ind >= n) return 0; // boundary case
       if (dp[ind] >= 0) return dp[ind];
       int take1 = INT_MIN, take2 = INT_MIN, take3 = INT_MIN;
       
       if (ind  + 2 < n) {
            take3 = (nums[ind] + nums[ind+1] + nums[ind+2]) - solve(nums, n, ind+3, dp);
       }
       if (ind + 1 < n) {
            take2 = (nums[ind] + nums[ind+1]) - solve(nums, n ,ind+2, dp);
       }
       take1 = nums[ind] - solve(nums, n, ind+1,dp);
       return dp[ind] = max(take1, max(take3, take2)); // each player maximisng advantage 
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() +1 , -1);
        int advantage_of_alice = solve(stoneValue, stoneValue.size(), 0, dp);
        // basically Solve(0) = alice's advantage - BObs advantage 
        if (advantage_of_alice == 0) return "Tie";
        else if (advantage_of_alice > 0) return  "Alice";
        else return  "Bob";
    }
};

class Solution {
public:
 //O(N) both TC and SC
    // advantage that the current player has it at ind 
    // each t=player have to maximise the advantage
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() +1 , -1);
        int n = stoneValue.size();
        // start from the end
        dp[n] = 0;
        for (int i = n -1; i >= 0; i--) {
            int take1 = INT_MIN, take2 = INT_MIN, take3 = INT_MIN;
            if (i  + 2 < n) {
                    take3 = (stoneValue[i] + stoneValue[i+1] + stoneValue[i+2]) - dp[i+3];
            }
            if (i + 1 < n) {
                    take2 = (stoneValue[i] + stoneValue[i+1]) - dp[i+2];
            }
            take1 = stoneValue[i] - dp[i+1];
            dp[i] = max(take1, max(take3, take2)); // each player maximisng advantage 
        }

        int advantage_of_alice = dp[0];
        // basically Solve(0) = alice's advantage - BObs advantage 
        if (advantage_of_alice == 0) return "Tie";
        else if (advantage_of_alice > 0) return  "Alice";
        else return  "Bob";
    }
};
 
class Solution {
public:
// space optimized dp
 //O(N) both TC
    // advantage that the current player has it at ind 
    // each t=player have to maximise the advantage
    string stoneGameIII(vector<int>& stoneValue) {
        // start from the end
        int n = stoneValue.size();
        int first = 0; int second = 0; int third = 0;
        for (int i = n -1; i >= 0; i--) {
            int take1 = INT_MIN, take2 = INT_MIN, take3 = INT_MIN;
            if (i  + 2 < n) {
                    take3 = (stoneValue[i] + stoneValue[i+1] + stoneValue[i+2]) - third;
            }
            if (i + 1 < n) {
                    take2 = (stoneValue[i] + stoneValue[i+1]) - second;
            }
            take1 = stoneValue[i] - first;
            third = second;
            second = first;
            first = max(take1, max(take3, take2)); // each player maximisng advantage 
        }
        int advantage_of_alice = first;
        // basically Solve(0) = alice's advantage - BObs advantage 
        if (advantage_of_alice == 0) return "Tie";
        else if (advantage_of_alice > 0) return  "Alice";
        else return  "Bob";
    }
};
