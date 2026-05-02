// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

 

// Constraints:

//     1 <= s.length <= 1000
//     s consists of lowercase English letters.

class Solution {
public:
    // two pointer apporach of O(N)
    int countSubstrings(string s) {
        int count = 0 ; int n = s.size();
        // first count all odd palindromes
        for (int k = 0; k < n; k++) {
            int i= k-1 ; int j= k + 1;
            while(i >=0 && j < n && s[i] == s[j]) {
                ++count; j++; i--;
            } 
        }
        // then count all even palindromes
        for (int k = 0; k < n; k++) {
            int i= k ; int j= k + 1;
            while(i >=0 && j < n && s[i] == s[j]) {
                ++count; j++; i--;
            } 
        }
        // each letters can be a palindrome
        return n + count;
    }
};


// dp inefficient solution
class Solution {
public:
    bool isPal(string& s,int i,int j) {
        while(i<j) {
            if(s[i] != s[j]) return false;
            ++i;--j;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1)) ;
        for(int i=0;i<s.size();++i) {
            for(int j=i;j<s.size();++j) {
                if(dp[i][j] < 0) {
                    dp[i][j] = isPal(s, i, j);
                }
            
                if(dp[i][j]) ++count;
            }
        }
        return count;
    }
};
