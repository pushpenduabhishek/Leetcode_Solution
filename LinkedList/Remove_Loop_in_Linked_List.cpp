/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        
        if(!head && !head->next) return;
        Node* temp=head;
        bool hasCycle=false;
        
        Node* slow=head;
        Node* fast=head;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            
            if(slow==fast){
                slow=head;
                hasCycle=true;
                break;
            }
        }
        
        if(hasCycle){
            
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            fast=fast->next;
            
            while(fast->next != slow){
                fast=fast->next;
            }
            fast->next=nullptr;
        }
    }
};
