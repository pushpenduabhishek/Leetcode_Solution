/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        deque<TreeNode*>q;
        q.push_back(root);
        bool dir=true;
        while(!q.empty()){
            int n=q.size();
            vector<int>res;
            for(int i=0; i<n; i++){
                if(dir){
                    TreeNode * temp=q.back();
                    q.pop_back();
                    if(temp->left) q.push_front(temp->left);
                    if(temp->right) q.push_front(temp->right);
                    res.push_back(temp->val);
                }else{
                    TreeNode* temp=q.front();
                    q.pop_front();
                    if(temp->right) q.push_back(temp->right);
                    if(temp->left) q.push_back(temp->left);
                    res.push_back(temp->val);
                }
            }
            dir=!dir;
            ans.push_back(res);
        }
        return ans;
    }
};
// @lc code=end

