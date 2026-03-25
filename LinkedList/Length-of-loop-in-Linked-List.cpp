/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow=head;
        Node* fast=head;
        Node* temp=head;
        
        bool cycleDetected=false;
        
        int count=1;
        
         while(fast && fast->next){
             slow=slow->next;
             fast=fast->next->next;
             if(slow==fast){
                cycleDetected=true;
                break;
             }
         }
         
         if(cycleDetected){
             slow=slow->next;
            while(slow != fast){
                count++;
                slow=slow->next;
            }
            return count;
         }
         
        return 0;
    }
};
