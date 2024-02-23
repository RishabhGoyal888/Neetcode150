class Node {
public: 
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int value){
        key = k;
        val = value;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node){
        Node* prevNode = right->prev;
        Node* nextNode = right;

        prevNode->next = node;
        nextNode->prev = node;
        node->prev = prevNode;
        node->next = nextNode;
    }

    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);

        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);

        if(cache.size() > cap ){
            Node* LRU = left->next;
            left->next = LRU->next;
            LRU->next->prev = left;

            cache.erase(LRU->key);
            delete(LRU);
        }
    }

    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */