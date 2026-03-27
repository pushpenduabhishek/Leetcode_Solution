/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
  Node* reverse(Node* head){
      Node* curr=head, *forw=head, *prev=nullptr;
      
      while(curr){
          forw=curr->next;
          curr->next=prev;
          prev=curr;
          curr=forw;
      }
      return prev;
  }
    Node* addOne(Node* head) {
        head=reverse(head);
        Node*temp=head;
        
        while(temp){
            if(temp->data<9){
                temp->data +=1;
                return reverse(head);
            }
            temp->data=0;
            temp=temp->next;
        }
        head=reverse(head);
        Node*leftCarry=new Node(1);
        leftCarry->next=head;
        
        return leftCarry;
        
    }
};
