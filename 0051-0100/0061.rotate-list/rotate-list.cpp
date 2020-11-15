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
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return head;
    ListNode* p = head;
    int len = 1;
    while (p->next) {
      p = p->next;
      ++len;
    }
    if (k == len) return head;
    p->next = head;
    k = k > len ? k % len : k;
    int n = len - k;
    ListNode* res = head;
    ListNode* dumb;
    while (n--) {
      dumb = res;
      res = res->next;
    }
    dumb->next = NULL;
    return res;
  }
};
