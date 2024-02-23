//created a diubly linked data struct with key and value 
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
    //using doubly linked list for LRU caching, keeping capacity in cap and storing the list between 2 boundary nodes left and right(these are for our reference only, they are not part of the mantained list we need to keep), adding the most recent node just before the right node, and so the least recent node will be the node just after the head, i.e just after the left node.
    int cap;
    unordered_map<int, Node*> cache;  //using hashing for keeping track, if key is already there with some value.
    Node* left;
    Node* right;

    LRUCache(int capacity) { //initialising, seting capacity and boundary nodes, and linking them
        cap = capacity;
        left = new Node(0,0);
        right = new Node(0,0);

        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()){  // if key is there, remove it and insert it again at the end so that it becomes the most recent node.
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()){ //if already there remove from list
            remove(cache[key]);
        }
        //these steps common if already in list or not
        cache[key] = new Node(key, value); //insert or update in cache table
        insert(cache[key]); //insert this node in list

        if(cache.size() > cap ){
            Node* LRU = left->next; //least recent used will be just after head, remove it and also erase from hash
            remove(LRU); 
            cache.erase(LRU->key);
            delete(LRU);
        }
    }

    //user added fucntions for inserting and removing a node from the list
    void remove(Node* node){ //removing node just after the head(left node)
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insert(Node* node){ //inserting node just before the tail(right node)
        Node* prevNode = right->prev;
        Node* nextNode = right;

        prevNode->next = node;
        nextNode->prev = node;
        node->prev = prevNode;
        node->next = nextNode;
    }
    
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */