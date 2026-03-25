/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==nullptr) return head;

        ListNode* dummyOdd = new ListNode(-1);
        ListNode* odd = dummyOdd;

        ListNode* dummyEven = new ListNode(-1);
        ListNode* even = dummyEven;

        int count=1;

        while(head){
            if(count%2==0){
                even->next=head;
                even=even->next;
                count++;
            }else{
                odd->next=head;
                odd=odd->next;
                count++;
            }
            head=head->next;
        }
        even->next=nullptr;
        odd->next=dummyEven->next;

        return dummyOdd->next;
    }
};
// @lc code=end

