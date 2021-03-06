/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//method1: iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *P = new ListNode(0);
        while(head){
            ListNode *first = P->next;
            P->next = head;
            head = head->next;
            P->next->next = first;
        }
        return P->next;
    }
};

//method2: recursive
class Solution {
public:
    void helper(ListNode* head, ListNode* H){
        if(!head) return;
        ListNode* first = H->next;
        H->next = head;
        ListNode* next = head->next;
        H->next->next = first;
        helper(next, H);
    }
 
    ListNode* reverseList(ListNode* head) {
        ListNode *H = new ListNode(0);
        helper(head, H);
        return H->next;
    }
};



//method 3
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};



//method 4
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)  return head;

        ListNode p(0);  p.next = head;

        ListNode *prev = head, *cur = head->next;

        while (cur) {
            prev->next = cur->next;
            cur->next = p.next;
            p.next = cur;
            cur = prev->next;
        }
        return p.next;
    }
};


//method 5
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)  return head;

        ListNode *p = new ListNode(0);  p->next = head;

        ListNode *prev = head, *cur = head->next;

        while (cur) {
            prev->next = cur->next;
            cur->next = p->next;
            p->next = cur;
            cur = prev->next;
        }
        return p->next;
    }
};
