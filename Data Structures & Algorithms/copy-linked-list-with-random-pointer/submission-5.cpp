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
        // create and save the copy one (new address but the same value) into hashmap 
        // when traversal the original linked list update the copy one
        unordered_map<Node*, Node*> mp;
        mp[NULL] = NULL;

        Node* curr = head;
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;

        while (curr) {
            Node* copy = mp[curr];
            copy->next = mp[curr->next];
            copy->random = mp[curr->random];
            curr = curr->next;
        }

        return mp[head];
    }
};
