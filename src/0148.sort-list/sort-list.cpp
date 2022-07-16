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
  ListNode* merge(ListNode* a, ListNode* b) {
    ListNode dummy;
    ListNode* p = &dummy;
    while (a && b) {
      if (a->val < b->val) {
        p->next = a;
        p = a;
        a = a->next;
      } else {
        p->next = b;
        p = b;
        b = b->next;
      }
    }
    p->next = a ? a : b;

    return dummy.next;
  }

  ListNode* cut(ListNode* head, int n) {
    auto p = head;
    while (--n && p) p = p->next;
    if (!p) return NULL;
    auto next = p->next;
    p->next = NULL;
    return next;
  }
  ListNode* sortList(ListNode* head) {
    ListNode dummy;
    dummy.next = head;
    ListNode* p = head;
    int len = 0;
    while (p) {
      p = p->next;
      ++len;
    }

    for (int i = 1; i != len; i <<= 1) {
      ListNode* cur = dummy.next;
      ListNode* tail = &dummy;

      while (cur) {
        ListNode* left = cur;
        ListNode* right = cut(cur, i);
        cur = cut(right, i);
        tail->next = merge(left, right);
        while (tail->next) tail = tail->next;
      }
    }
    return dummy.next;
  }
};
