// Time Complexity: O(n * logk)
// Space Complexity: O(k)

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
        ListNode *mergeKLists(vector<ListNode *> &lists) {
            return mergeKLists(lists, 0, lists.size() - 1);
        }
    private:
        ListNode *mergeKLists(vector<ListNode *> &lists, int begin, int end) {
            if(begin > end)
                return NULL;
            if(begin == end)
                return lists[begin];
            return mergeTwoLists(mergeKLists(lists, begin, (begin + end) / 2), mergeKLists(lists, (begin + end) / 2 + 1, end));
        }

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
