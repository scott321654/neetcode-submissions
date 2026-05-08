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
private:
    ListNode* mergeList(ListNode* list1, ListNode* list2)
    {
        ListNode* dummyNode = new ListNode();
        ListNode* curr = dummyNode;

        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                curr->next = list1;
                list1 = list1->next;
            }
            else 
            {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        if (list1)
        {
            curr->next = list1;
        }
        else
        {
            curr->next = list2;
        }
    
        return dummyNode->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0) {
            return NULL;
        }

        while (n > 1) {
            for (int i = 0; i < n / 2; i++) {
                lists[i] = mergeList(lists[i], lists[n - i - 1]);
            }
            n = (n + 1) / 2;
        }

        return lists.front();
    }
};
