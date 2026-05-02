// Given a string s, return the longest in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:

// Input: s = "cbbd"
// Output: "bb"

/*
THe idea is iterate through every possible substring and check if palindrom, if yes store the result to remeber the computation
  */

// i would say very stupid and inefficient
// TC - O(N2) SC - O(2N)
class Solution {
public:
    int find_length_palindrome(int i, int j, string& s ){
        if (i>j) return 0;
        int leftptr =i; int rightptr = j;
        while (leftptr <= rightptr) {
            if (s[leftptr] != s[rightptr]) return 0;
            leftptr++; rightptr--;
        }
        return (j-i)+1;
    }
    string longestPalindrome(string s) {
        
        vector<vector<int>> dp(s.size(), vector<int> (s.size(), -1));
        int maxi = 0; int max_i = 0; int max_j = 0;

        for(int i =0; i< s.size(); i++) {
            for(int j=s.size()-1; j >=i; j--) {

                if(dp[i][j] < 0) {
                    dp[i][j] = find_length_palindrome(i, j, s);
                } 
                int length_of_palindrome = dp[i][j];
                
                if (length_of_palindrome > maxi) {
                     maxi = length_of_palindrome;
                     max_i = i; max_j = j;
                }
            }
        }
        return s.substr(max_i, max_j - max_i + 1);
    }
};

// O(N) solution
class Solution {
public:
    // appproach is expand from center of palindrom
    // two ways total length can be even or odd
    string longestPalindrome(string s) {
        int n = s.size() ; int maxLength = 1; int startIndex = 0; // one char is always palindrome

        // considering only odd lenth palindromes
        for(int i = 0; i< n ; i++) {
            int k = i - 1; int j = i + 1;
            while (k >= 0 && j < n) {
                if (s[k] != s[j]) break; // boundary
                if (maxLength < (j - k +1)) {
                    maxLength = j - k + 1;
                    startIndex = k;
                }
                k--; j++;
            }
        }
        // consider even length palindromes
        for(int i = 0; i< n; i++) {
            int k = i ; int j = i + 1;
            while (k >= 0 && j < n) {
                if (s[k] != s[j]) break; // boundary
                if (maxLength < (j - k +1)) {
                    maxLength = j - k + 1;
                    startIndex = k;
                }
                k--; j++; 
            }
        }     
        return s.substr(startIndex,  maxLength);
    }
};
