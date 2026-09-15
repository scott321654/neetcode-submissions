struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    unordered_map<int, Node*> cache;
    int cap;
    Node *lsb;
    Node *msb;

    void remove(Node *node) {
        Node *nxt = node->next;
        Node *prv = node->prev;
        nxt->prev = prv;
        prv->next = nxt;
    }   

    void insert(Node *node) {
        Node *tmp = msb->prev;
        tmp->next = node;
        node->next = msb;
        node->prev = tmp;
        msb->prev = node;
    }   

public:
    LRUCache(int capacity) {
        cap = capacity;
        lsb = new Node(0, 0);
        msb = new Node(0, 0);
        lsb->next = msb;
        msb->prev = lsb;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        Node *node = cache[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* node = cache[key];
            remove(node);
            node->value = value;
            insert(node);
            return;
        }

        if (cache.size() == cap) {
            Node *lru = lsb->next;
            Node *nxt = lru->next;
            lsb->next = nxt;
            nxt->prev = lsb;
            cache.erase(lru->key);
        }
        cache[key] = new Node(key, value);
        insert(cache[key]);
    }
};
