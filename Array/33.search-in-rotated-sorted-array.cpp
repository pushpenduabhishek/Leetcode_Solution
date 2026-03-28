/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]==target){
                ans=mid;
            }
            if(nums[mid]>=nums[low]){
                if(nums[mid]>target && nums[low]<=target){
                    high = mid-1;
                }else{
                    low=mid+1;
                }
            }else {
                if(nums[mid]<=target && nums[high]>=target){
                    low = mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

