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
    ListNode *reverse(ListNode *head) {
        if (!head) return NULL;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        return prev;
    }

public:
    void reorderList(ListNode* head) {
        // fast and slow pointer to find medium 
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = NULL;

        while (fast && fast->next) { //  I don't remember why
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL; 
        second = reverse(second);

        ListNode* first = head;
        
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }

    }
};
