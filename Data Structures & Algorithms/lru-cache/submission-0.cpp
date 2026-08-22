class Node {
public:

    int key;
    int value;
    Node* next;
    Node* prev;
    Node(int k, int v) : key(k), value(v), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int , Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        left = new Node(0, 0);  // LRU
        right = new Node(0, 0); // MRU
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            insert(node);

            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
        }

        Node *newnode = new Node(key, value);
        cache[key] = newnode;
        insert(newnode);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};
