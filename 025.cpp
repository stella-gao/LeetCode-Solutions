/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !(head->next) || k == 1)   return head;
        
        ListNode *cnt = head;
        for (int i = 0; i < k; i++)
            if (cnt)       cnt = cnt->next;
            else           return head;

        ListNode *prev = NULL, *cur = head, *next = NULL;
        while (cur != cnt) {
            next = cur->next;
            if (prev)       cur->next = prev;
            else            cur->next = reverseKGroup(cnt, k);
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
