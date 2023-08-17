class LRUCache {
public:

    class Node{
        public :
        Node* next;
        Node* pre;
        int key;
        int val;

        Node(int key_ , int val_){
            next = NULL;
            pre = NULL;
            key = key_;
            val = val_;
        }
    };

    Node* tail = new Node(-1 , -1);
    Node* head = new Node(-1 , -1);
    int cap;
    unordered_map<int , Node*> ourmap;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->pre = head;
    }

  void deleteNode(Node* delnode){
        Node* prevv = delnode -> pre;
        Node* nextt = delnode -> next;

        prevv -> next = nextt;
        nextt -> pre = prevv;
    }

    void addNode(Node* newnode){
        Node* temp = head -> next;

        newnode -> next = temp;
        newnode -> pre = head;

        head -> next = newnode;
        temp -> pre = newnode;
    }
    int get(int key) {
        if(ourmap.find(key) == ourmap.end()) return -1;
        Node* cur = ourmap[key];
        int value = cur->val;
        ourmap.erase(key);
        deleteNode(cur);
        addNode(cur);
        ourmap[key] = head -> next;
        return value;
    }

    void put(int key, int value) {
        if(ourmap.find(key) != ourmap.end()){
            Node* cur = ourmap[key];
            ourmap.erase(key);
            deleteNode(cur);
        }
        if(ourmap.size() == cap){
            cout<<"Key "<<tail->pre->key<<endl;
            ourmap.erase(tail -> pre-> key);
            cout<<ourmap.count(2)<<endl;
            deleteNode(tail -> pre);
        }

        addNode(new Node(key , value));
        ourmap[key] = head->next;
    }
};