/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    if (!head) return;
    ListNode* faster = *slower = head;
    ListNode *s = head, *tmp;
    while (faster->next) {
      slower = slower->next;
      faster = faster->next;
      if (faster->next) faster = faster->next;
    }
    faster = slower->next;
    slower->next = nullptr;
    while (faster) {
      tmp = faster->next;
      faster->next = slower->next;
      slower->next = faster;
      faster = tmp;
    }
    faster = slower->next;
    slower->next = nullptr;
    while (faster) {
      tmp = faster->next;
      faster->next = s->next;
      s->next = faster;
      s = faster->next;
    }
  }
};
