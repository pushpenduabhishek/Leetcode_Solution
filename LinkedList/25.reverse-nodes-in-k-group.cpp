/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode *findkthNode(ListNode *head, int k){
        while(head!=nullptr && k>1){
            head=head->next;
            k--;
        }
        return head;
    }

    void reverseNode(ListNode * temp){
        ListNode *curr=temp;
        ListNode *forw=temp;
        ListNode *prev=nullptr;
        while(curr != nullptr){
            forw=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forw;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head, *prev=nullptr;
            while(temp!=nullptr){
            ListNode *kth= findkthNode(temp,k);
            
            if(kth==nullptr){
                if(prev != nullptr){
                    prev->next=temp;
                    break;
                }
            }
            ListNode *nextNode=kth->next;
            kth->next=nullptr;
            reverseNode(temp);

            if(prev==nullptr){
                head=kth;
            }else{
                prev->next=kth;
            }
            prev=temp;
            temp=nextNode;
            }
        return head;
    }
};
// @lc code=end

