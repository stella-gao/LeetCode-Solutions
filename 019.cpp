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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *H = new ListNode(0);
        H->next = head;
        ListNode *ps = H, *pf = H, *ret;
        for(int i=0; i<n; ++i) pf = pf->next;
        while(pf){
            ret = ps;
            ps = ps->next;
            pf = pf->next;
        }
        ret->next = ps->next;
        return H->next;
    }
};
