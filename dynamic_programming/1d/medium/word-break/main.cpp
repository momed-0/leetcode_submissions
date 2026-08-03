// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

// Example 1:

// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".

// Example 2:

// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.

// Example 3:

// Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
// Output: false

 

// Constraints:

//     1 <= s.length <= 300
//     1 <= wordDict.length <= 1000
//     1 <= wordDict[i].length <= 20
//     s and wordDict[i] consist of only lowercase English letters.
//     All the strings of wordDict are unique.


// brute solution
class Solution {
public:

    // here ind, means till where in the target string that we where able to match from word dict
    bool solve(string s, vector<string>& wordDict, int ind) {
        if (ind >= s.size()) return true; // we were able to match everything

        // for each word in dictionary, check if we can match from this ind variable
        bool result = false;
        for(int i=0; i < wordDict.size(); i++) {
            if ((ind + wordDict[i].size() -1 ) >=  s.size()) continue; // can't fit in the word

            if (s.substr(ind, wordDict[i].size() ) == wordDict[i]) {
                // this word can be matched to our target; one step closer, recurse it again
                // now we have solved the string till ind + wordDic[i].size, so start the recursion
                // after that, return early if we enounter a true
                result = result ||  solve(s, wordDict, ind + wordDict[i].size());
            }
        }
        // we couldn't match the striung with dict
        return result;
    } 
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s,  wordDict,  0);
    }
};

// 1D dp
// TC O(N) , SC O(N)
class Solution {
public:

    // here ind, means till where in the target string that we where able to match from word dict
    bool solve(string s, vector<string>& wordDict, int ind, vector<int>& hash_map) {
        if (ind >= s.size()) return true; // we were able to match everything
        if ( hash_map[ind] >= 0 ) return hash_map[ind];

        // for each word in dictionary, check if we can match from this ind variable
        bool result = false;
        for(int i=0; i < wordDict.size(); i++) {
            if ((ind + wordDict[i].size() -1 ) >=  s.size()) continue; // can't fit in the word

            if (s.substr(ind, wordDict[i].size() ) == wordDict[i]) {
                // this word can be matched to our target; one step closer, recurse it again
                // now we have solved the string till ind + wordDic[i].size, so start the recursion
                // after that, return early if we enounter a true
                result = result ||  solve(s, wordDict, ind + wordDict[i].size(), hash_map);
            }
        }
        // we couldn't match the striung with dict
        return hash_map[ind] =  result;
    } 
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> hash_map (s.size() +1, -1);
        return solve(s,  wordDict,  0, hash_map);
    }
};

// bottom up solutuon, start from the end and go to the start 
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[s.size()] = true; // empty string is always valid
 
        for (int i = s.size() - 1; i >= 0; i--) {
            for (const auto& w : wordDict) {
                if ((i + w.size()) <= s.size() &&
                     s.substr(i, w.size()) == w) {
                    dp[i] = dp[i + w.size()];
                }
                if (dp[i]) { // exit early
                    break;
                }
            }
        }

        return dp[0];
    }
};
