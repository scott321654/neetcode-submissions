class Node {
public:
    int key;
    int val;
    Node *prev;
    Node *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    unordered_map<int, Node*> mp;
    int cap;
    Node *left;
    Node *right;

void remove(Node* node) {
    Node *nxt = node->next;
    Node *prv = node->prev;
    prv->next = nxt;
    nxt->prev = prv;
}

void insert(Node* node) {
    Node* prv = right->prev;
    prv->next = node;
    node->prev = prv;
    node->next = right;
    right->prev = node;
}

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (mp.count(key)) {
            Node* node = mp[key];
            remove(node); //LSB
            insert(node); //MSB
            return node->val;
        } 
        return -1;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* tmp = mp[key];
            remove(tmp);
            tmp->val = value;
            insert(tmp);
            return;
        } 

        if (mp.size() == cap) {
            Node *lru = left->next;
            remove(lru);
            mp.erase(lru->key);
        }

        mp[key] = new Node(key ,value);
        insert(mp[key]);
        
        return;
    }
};
