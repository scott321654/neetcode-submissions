class LRUCache {
private:
    typedef struct ListNode {
        int val;
        int key;
        struct ListNode* next;
        struct ListNode* prev;
        ListNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr){}
    } ListNode;
    
    void remove(ListNode* node) {
        ListNode* tmp = node->next;
        ListNode* tmp1 = node->prev;
        tmp1->next = tmp;
        tmp->prev = tmp1;
    }

    void insert(ListNode* node) {
        ListNode* tmp = right->prev;
        tmp->next = node;
        node->prev = tmp;
        node->next = right;
        right->prev = node;
    }

public:
    // left node => LRU
    // right node => MRU
    // get -> remove LRU update MRU
    // put -> oversize 
    // operate in O(1) => hashtable
    unordered_map<int, ListNode*> mp;
    int cap;
    ListNode *left;
    ListNode *right;

    LRUCache(int capacity) {
        cap = capacity;
        left = new ListNode(0, 0);
        right = new ListNode(0, 0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (mp.count(key)) {
            ListNode* node = mp[key];
            remove(node);
            insert(node);
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            ListNode* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
        } else { 
            if (mp.size() >= cap) {
                ListNode* lru = left->next;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
            mp[key] = new ListNode(key, value);
            insert(mp[key]);
        }
    }
};
