// You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

// "1" -> 'A'

// "2" -> 'B'

// ...

// "25" -> 'Y'

// "26" -> 'Z'

// However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

// For example, "11106" can be decoded into:

//     "AAJF" with the grouping (1, 1, 10, 6)
//     "KJF" with the grouping (11, 10, 6)
//     The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).

// Note: there may be strings that are impossible to decode.

// Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.

// The test cases are generated so that the answer fits in a 32-bit integer.

 

// Example 1:

// Input: s = "12"

// Output: 2

// Explanation:

// "12" could be decoded as "AB" (1 2) or "L" (12).

// Example 2:

// Input: s = "226"

// Output: 3

// Explanation:

// "226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

// Example 3:

// Input: s = "06"

// Output: 0

// Explanation:

// "06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.

 

// Constraints:

//     1 <= s.length <= 100
//     s contains only digits and may contain leading zero(s).


//O(N) TC + O(N)  space
class Solution {
public:
    int solve(int i,  string s, vector<int>& dp) {
        if (i >= s.size()) return 1; // decoded all the codes, add to the count
        if (dp[i] >=0 ) return dp[i];

        int number= s[i] - '0';
        if (number  ==  0) return 0; // no way we can go from a 0, it should be grouped before
        int individual = solve(i + 1, s, dp) ;// moving forward by taking single digit
        
        if (i+1 >= s.size()) return dp[i]= individual;
        int nextNumber = s[i+1] - '0';
        int groupedNumber = number*10 + nextNumber;
        int tryToGroup = 0;
        if (groupedNumber >= 10 && groupedNumber <= 26) {
                    tryToGroup = solve(i+2, s , dp);
        }
        return dp[i] = individual + tryToGroup;
    }
    int numDecodings(string s) {
        if (s[0] == '0'|| s.size() == 0) return 0;
        vector<int> dp(s.size() , -1);
        return solve(0, s, dp);
    }
};

//tabulation but still ON space
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else {
                dp[i] = dp[i + 1];
                if (i + 1 < s.size() && (s[i] == '1' ||
                    s[i] == '2' && s[i + 1] < '7')) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
};



// Space optimized

class Solution {
public:
    int numDecodings(string s) {
        int dp = 0, dp2 = 0;
        int dp1 = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                dp = 0;
            } else {
                dp = dp1;
                if (i + 1 < s.size() && (s[i] == '1' ||
                    s[i] == '2' && s[i + 1] < '7')) {
                    dp += dp2;
                }
            }
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};
