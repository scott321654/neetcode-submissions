/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int nodeCount = 0;  
        ListNode *dummy = new ListNode(0, head);
        ListNode *node = head;

        while (node) {
            node = node->next;
            ++nodeCount;
        }
        
        int remain = nodeCount - n;
        int curr_count = 0;

        ListNode *prev = dummy;

        while (curr_count != remain) {
            prev = prev->next;
            curr_count++;
        }

        ListNode *target = prev->next;
        prev->next = target->next;
        delete target;

        return dummy->next;
    }
};
