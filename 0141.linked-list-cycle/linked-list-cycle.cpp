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
  bool hasCycle(ListNode* head) {
    if (!head) return false;

    ListNode *faster{head}, *slower{head};
    while (faster && faster->next) {
      faster = faster->next->next;
      slower = slower->next;
      if (faster == slower) return true;
    }
    return false;
  }
};
