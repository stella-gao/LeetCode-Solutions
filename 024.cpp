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
    ListNode *swapPairs(ListNode *head) {
        ListNode *H = new ListNode(0);
        H->next = head;
        
        ListNode *pre = H, *cur = head;
        int cnt = 1;
        while (cur != NULL && cur->next != NULL) {
            ListNode *tmp = cur->next;
            pre->next = tmp;
            cur->next = tmp->next;
            tmp->next = cur;
            
            pre = cur;
            cur = cur->next;
        }
        head = H->next;
        delete H;
        return head;
    }
};

