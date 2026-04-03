/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();

        for(int i=n-1; i>=0; i--){
            if(digits[i]<9){
                digits[i] +=1;
                return digits;
            }

            digits[i]=0;
        }

        vector<int>ans(n+1,0);
        ans[0]=1;

        return ans;
    }
};
// @lc code=end

