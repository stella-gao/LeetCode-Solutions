/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*method 1: 我们可以使用两个指针来做，pre指向奇节点，cur指向偶节点，
然后把偶节点cur后面的那个奇节点提前到pre的后面，
然后pre和cur各自前进一步，
此时cur又指向偶节点，pre指向当前奇节点的末尾，
以此类推直至把所有的偶节点都提前了即可*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pre = head, *cur = head->next;
        while (cur && cur->next) {
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            cur = cur->next;
            pre = pre->next;
        }
        return head;
    }
};


/*method 2: 用两个奇偶指针分别指向奇偶节点的起始位置，另外需要一个单独的指针even_head来保存偶节点的起点位置，
然后把奇节点的指向偶节点的下一个(一定是奇节点)，此奇节点后移一步，
再把偶节点指向下一个奇节点的下一个(一定是偶节点)，此偶节点后移一步，
以此类推直至末尾，此时把分开的偶节点的链表连在奇节点的链表后即可*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *even_head = even;
        while (even && even->next) {
            odd = odd->next = even->next;
            even = even->next = odd->next;
        }
        odd->next = even_head;
        return head;
    }
};


class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *odd = head, *even = head->next, *even_head = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = even_head;
        return head;
    }
};
