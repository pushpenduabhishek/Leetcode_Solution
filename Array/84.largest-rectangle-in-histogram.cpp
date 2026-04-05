/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>= heights[i]) st.pop();
            if(st.empty()) pse[i]=-1;
            else pse[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>= heights[i]) st.pop();
            if(st.empty()) nse[i]=n;
            else nse[i]=st.top();
            st.push(i);
        }
        int maxArea=INT_MIN;
        for(int i=0; i<n; i++){
            maxArea= max(maxArea,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxArea;

    }
};
// @lc code=end

