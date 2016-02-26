/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// We cannot really delete the given node, but just delete its next node after copying the data of the next node to it.
// After moving the next node to the given node, then we can delete the next node.

// method 1
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        *node = *next;
        // this statement is equivalent to
        // node->val = next->val;
        // node->next = next->next;
        delete next;
    }
};

// method 2
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node -> next;
    }
};
