class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *left, *right, *p;
    ListNode* dummy1 = new ListNode(0);
    ListNode* dummy2 = new ListNode(0);
    p = head, left = dummy1, right = dummy2;

    while (p) {
      if (p->val < x) {
        left->next = p;
        left = left->next;
      } else {
        right->next = p;
        right = right->next;
      }
      p = p->next;
    }
    left->next = dummy2->next;
    right->next = NULL;
    return dummy1->next;
  }
};
