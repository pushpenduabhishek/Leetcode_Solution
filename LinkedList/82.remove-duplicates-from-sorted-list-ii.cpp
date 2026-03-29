/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp=dummy;
        ListNode* curr=head;
        int dupVal=-1;
        while(curr){
            if(curr->next && curr->val==curr->next->val){
                dupVal=curr->val;

                while(curr && curr->val==dupVal){
                    curr=curr->next;
                }
        
            }else{
                temp->next=curr;
                temp=temp->next;
                curr=curr->next;
            }     
        }
        temp->next=nullptr;
        return dummy->next;
        
    }
};
// @lc code=end

