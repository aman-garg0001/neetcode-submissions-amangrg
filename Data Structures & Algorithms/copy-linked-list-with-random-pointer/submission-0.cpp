/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> nodeMap;
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return NULL;
        }

        if (nodeMap.find(head) == nodeMap.end()) {
            nodeMap[head] = new Node(head->val);
            nodeMap[head]->next = copyRandomList(head->next);
            nodeMap[head]->random = copyRandomList(head->random);
        }

        return nodeMap[head];
    }
};