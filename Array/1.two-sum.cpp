/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> m1;
        for(int i=0; i<nums.size(); i++){
            int x=nums[i];
            int res=target-nums[i];

            if(m1.find(res) != m1.end()){
                return {m1[res],i};
            }
            m1[x]=i;
        }
        return {};
    }
};
// @lc code=end

