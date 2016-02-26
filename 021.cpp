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
   ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
            ListNode head(INT_MIN);
            ListNode *p = &head;
            for(; l1 && l2; p = p->next) {
                if(l1->val < l2->val) {
                    p->next = l1;
                    l1 = l1->next;
                }
                else {
                    p->next = l2;
                    l2 = l2->next;
                }
            }
            if(l1) {
                p->next = l1;
            }
            else {
                p->next = l2;
            }

            return head.next;
        }
};

