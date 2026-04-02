/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        unordered_map<char, int>mp;
        int left=0;
        int len=INT_MIN;
        for(int i=0; i<n; i++){

            if(mp[s[i]] != mp.end() && mp[s[i]]>=left){
                left=mp[s[i]] + 1;
            }
            mp[s[i]]=i;
            len = max(len,i-left+1);
        }
        return len;
        
    }
};
// @lc code=end

