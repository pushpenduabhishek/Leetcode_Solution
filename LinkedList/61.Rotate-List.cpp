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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        ListNode* curr=head,*temp=head;
        int count=0;
        while(curr){
            count++;
            curr=curr->next;
        }
        if(k%count==0) return head;

        int t=count - (k%count);
        while(temp && t>1){
            temp=temp->next;
            t--;
        }
        ListNode* nextNode=temp->next;
        temp->next=nullptr;
        ListNode* last=nextNode;

        while(last->next !=nullptr){
            last=last->next;
        }
        last->next=head;
        return nextNode;
        
    }
};
