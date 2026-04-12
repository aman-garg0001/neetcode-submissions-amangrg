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
        ListNode* prev = NULL;
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        for (int i = 0; i < n; i++) {
            ptr2 = ptr2->next;
        }
        while (ptr2 != NULL) {
            ptr2 = ptr2->next;
            prev = ptr1;
            ptr1 = ptr1->next;
        }
        if (prev == NULL) {
            return ptr1->next;
        } else {
            prev->next = ptr1->next;
            return head;
        }
    }
};