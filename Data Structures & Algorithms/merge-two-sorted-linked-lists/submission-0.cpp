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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head;
        ListNode* node;
        if (list1 == NULL) {
            return list2;
        } else if (list2 == NULL) {
            return list1;
        } else if (list1 == NULL and list2 == NULL) {
            return NULL;
        } else {
            if (list1->val <= list2->val) {
                head = list1;
                list1 = list1->next;
            } else {
                head = list2;
                list2 = list2->next;
            }
        }

        node = head;
        
        while (list1 and list2) {
            if (list1->val <= list2->val) {
                node->next = list1;
                list1 = list1->next;
            } else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }

        while (list1) {
            node->next = list1;
            list1 = list1->next;
            node = node->next;
        }

        while (list2) {
            node->next = list2;
            list2 = list2->next;
            node = node->next;
        }

        return head;
    }
};
