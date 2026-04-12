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
    bool hasCycle(ListNode* head) {
        if (head == NULL) {
            return false;
        }
        ListNode* ptr1 = head;
        ListNode* ptr2 = head->next;

        while (ptr1 != NULL and ptr2 != NULL) {
            if (ptr1 == ptr2) {
                return true;
            }
            ptr1 = ptr1->next;
            if (ptr2->next != NULL) {
                ptr2 = ptr2->next->next;
            } else {
                break;
            }
        }

        return false;
    }
};
