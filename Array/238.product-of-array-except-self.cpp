/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> result;
        vector<int> prefix;
        vector<int>suffix;

        int temp1=1;
        for(int i=0; i<nums.size(); i++){
            temp1 *= nums[i];
            prefix.push_back(temp1);
        }

        int temp2=1;
        for(int i=nums.size()-1; i>=0; i--){
            temp2 *= nums[i];
            suffix.insert(suffix.begin(),temp2);
        }

        for(int i=0; i<nums.size(); i++){
            if(i==0){
                result.push_back(suffix[i+1]);
            }else if(i==nums.size()-1){
                result.push_back(prefix[i-1]);
            }else {
                result.push_back(prefix[i-1] * suffix[i+1]);
            }
        }
        return result ;
    }
};
// @lc code=end

