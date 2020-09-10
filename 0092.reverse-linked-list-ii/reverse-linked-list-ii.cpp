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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    int cnt = 1;
    ListNode dummy;
    dummy.next = head;
    ListNode* node = &dummy;
    while (cnt++ != m) node = node->next;
    head = node->next;
    for (int i = m; i != n; ++i) {
      ListNode* tmp = head->next;
      head->next = tmp->next;
      tmp->next = node->next;
      node->next = tmp;
    }
    return dummy.next;
  }
};
