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
 
        ListNode *dummy = new ListNode();
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;
        int move_cnt = 0;

        while (move_cnt < n) {
            fast = fast->next;
            ++move_cnt;
        }
        ListNode *prev = nullptr;

        while (fast) {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        ListNode * tmp = slow;
        prev->next = slow->next;
        delete slow;

        return dummy->next;
    }   
};
