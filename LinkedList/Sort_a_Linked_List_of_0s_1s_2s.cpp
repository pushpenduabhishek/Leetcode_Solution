/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
       Node* dummyZero = new Node(-1);
       Node* temp0=dummyZero;
       
       Node* dummyOne= new Node(-1);
       Node* temp1=dummyOne;
       
       Node* dummyTwo = new Node(-1);
       Node* temp2=dummyTwo;
       
       while(head){
           if(head->data==0){
               temp0->next=head;
               temp0=temp0->next;
           }else if(head->data==1){
               temp1->next=head;
               temp1=temp1->next;
           }else{
               temp2->next=head;
               temp2=temp2->next;
           }
           head=head->next;
       }
       
       temp2->next=nullptr;
       
      if(!dummyZero->next && !dummyOne->next){
          return dummyTwo->next;
          
      }else if(!dummyZero->next && dummyOne->next){
          temp1->next=dummyTwo->next;
          return dummyOne->next;
          
      }else if(dummyZero->next && !dummyOne->next){
          temp0->next=dummyTwo->next;
          return dummyZero->next;
      }
      
       temp0->next=dummyOne->next;
       temp1->next=dummyTwo->next;
       
       return dummyZero->next;
    }
};
