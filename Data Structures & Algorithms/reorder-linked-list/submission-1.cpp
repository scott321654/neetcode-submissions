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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *next;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    };

    void reorderList(ListNode* head) {
        int length = 0;
        ListNode *fast = head;
        ListNode *slow = head;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second  = slow->next;
        slow->next = nullptr;
        second = reverseList(second);
        
        ListNode *first = head;

        while (second) {
            ListNode *next1 = first->next;   // 存 first 下一步
            ListNode *next2 = second->next;  // 存 second 下一步

            first->next = second;   // first 指向 second
            second->next = next1;   // second 指向原本的 first 下一步

            first = next1;          // first 往前走
            second = next2;         // second 往前走
        }
    }
};
