/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    int binaryLeft(vector<int> arr, int target){
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=target){
                if(arr[mid]==target) ans=mid;
                high = mid-1;
            }else {
                low=mid+1;
            }
        }
        return ans;
    }
    int binaryRight(vector<int> arr, int target){
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<=target){
                if(arr[mid]==target) ans=mid;
                low=mid+1;
            }else {
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int x = binaryLeft(nums, target);
        int y = binaryRight(nums, target);
        
        return {x,y};

    }
};
// @lc code=end

