// Time Complexity: O(n)
// Space Complexity: O(1)

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
        ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            ListNode org(INT_MIN);
            ListNode *p = &org;
            int flag = 0;

            for(; l1 || l2; p = p->next) {
                const int v1 = (l1)? l1->val : 0;
                const int v2 = (l2)? l2->val : 0;
                p->next = new ListNode((v1 + v2 + flag) % 10);
                flag = (v1 + v2 + flag) / 10;
                if(l1) l1 = l1->next;
                if(l2) l2 = l2->next;
            }

            if(flag)
                p->next = new ListNode(flag);

            return org.next;
        }
};
