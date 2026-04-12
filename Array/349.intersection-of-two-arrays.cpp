/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        unordered_set<int>mp(nums1.begin(),nums1.end());
        vector<int>ans;

        for(int i=0; i<n; i++){
            if(mp.count(nums2[i])){
                ans.push_back(nums2[i]);
                mp.erase(nums2[i]);
            }
        }
        return ans;
    }
};
// @lc code=end

