/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0,r=1;
        while(r<nums.size()){
             if(nums[l]!=nums[r]){
                nums[l+1]=nums[r];
                l++;
             }else{
                r++;
             }
        }
        return l+1;
    }
};
// @lc code=end

