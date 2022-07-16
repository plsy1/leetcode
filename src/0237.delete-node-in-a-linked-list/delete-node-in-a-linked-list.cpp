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
  void deleteNode(ListNode* node) {
    ListNode* foo = node->next;
    node->val = foo->val;
    node->next = foo->next;
    delete foo;
  }
};
