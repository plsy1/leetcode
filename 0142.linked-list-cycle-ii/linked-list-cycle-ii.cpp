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
  ListNode *detectCycle(ListNode *head) {
    if (!head) return NULL;

    ListNode *faster{head}, *slower{head};
    while (faster && faster->next) {
      faster = faster->next->next;
      slower = slower->next;
      if (faster == slower) {
        slower = head;
        while (slower != faster) {
          slower = slower->next;
          faster = faster->next;
        }
        return faster;
      }
    }
    return NULL;
  }
};
