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
    void reorderList(ListNode* head) {
        ListNode *ptr1 = head;
        ListNode *ptr2 = head->next;

        while (ptr2) {
            ptr1 = ptr1->next;
            if (ptr2->next) {
                ptr2 = ptr2->next->next;
            } else {
                break;
            }
        }

        ptr2 = ptr1->next;
        ptr1->next = NULL;
        ptr2 = reverseList(ptr2);
        ptr1 = head;
        
        while (ptr1 && ptr2) {
            // cout << ptr1->val << " " << ptr2->val << endl;
            ListNode* temp1 = ptr1->next;
            ListNode* temp2 = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = temp1;
            ptr2 = temp2;
            ptr1 = temp1;
        }
    }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* next = head;
        while (next) {
            ListNode* temp = next->next;
            next->next = prev;
            prev = next;
            next = temp;
        }
        return prev;
    }
};