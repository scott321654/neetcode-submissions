/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* old = head;

        while (old) {
            Node* newNode = new Node(old->val);
            mp[old] = newNode;
            old = old->next;
        }

        old = head;

        while (old) {
            Node* copy;
            copy= mp[old];
            copy->next = mp[old->next];
            copy->random = mp[old->random];
            old = old->next;
        }

        return mp[head];
    }
};
