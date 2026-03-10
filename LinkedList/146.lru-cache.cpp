/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int k, int v){
            key=k;
            value=v;
            next=nullptr;
            prev=nullptr;
        }
    };
    int limit;
    Node *head;
    Node *tail;
    LRUCache(int capacity) {
        limit=capacity;
        head =new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    unordered_map<int, Node*> map;
    void insertNode(Node * newNode){
        Node *nextNode=head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=nextNode;
        nextNode->prev=newNode;
    }
    void deleteNode(Node *newNode){
        Node *prevNode= newNode->prev;
        Node *nextNode=newNode->next;
        prevNode->next=nextNode;
        nextNode->prev= prevNode;
    }
    int get(int key) {
        if(map.find(key) != map.end()){
            Node * tbd=map[key];
            deleteNode(tbd);
            insertNode(tbd);
            return tbd->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            Node* tbd= map[key];
            deleteNode(tbd);
            Node *newNode = new Node(key,value);
            map[key]=newNode;
            insertNode(newNode);
        }else{
            if(map.size()==limit){
                Node *tbd=tail->prev;
                map.erase(tbd->key);
                deleteNode(tbd);
            }
            Node *newNode=new Node(key,value);
            map[key]=newNode;
            insertNode(newNode);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

