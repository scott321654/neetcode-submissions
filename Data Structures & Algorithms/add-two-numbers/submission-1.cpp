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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { 
ListNode dummy(0);      // 建立假頭節點，避免額外的 new 與 memory leak
        ListNode* curr = &dummy;
        int carry = 0;

        // 只要 l1 或 l2 還沒走完，或者還有進位，就繼續計算
        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            curr->next = new ListNode(sum % 10); // 存入當前個位數
            curr = curr->next;
            carry = sum / 10;           // 計算新的進位

        }

        return dummy.next;
    }
};
