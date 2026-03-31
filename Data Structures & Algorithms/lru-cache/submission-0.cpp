class Node{
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), val(v), prev(nullptr), next(nullptr){}
};
class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    void insert(Node * node){
        Node * pre = right->prev;
        pre->next = node; 
        node ->next = right;
        right->prev = node;
        node->prev = pre;
    }
    void remove(Node * node){
        Node* pre = node->prev;
        Node* nxt = node->next;
        nxt -> prev = pre;
        pre -> next = nxt;
    }
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()) remove(cache[key]);
        Node* newnode = new Node(key,value);
        insert(newnode);
        cache[key] = newnode;
        if(cache.size()>cap){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }

    }
};
