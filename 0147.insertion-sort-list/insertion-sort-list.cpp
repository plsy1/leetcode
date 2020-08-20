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
  ListNode* insertionSortList(ListNode* head) {
    ListNode* dummy = new ListNode(INT_MIN);
    dummy->next = head;

    ListNode* preNode = dummy;
    while (head) {
      ListNode* curNode = head;
      head = head->next;

      if (preNode->val <= curNode->val) {
        preNode = curNode;
        continue;
      }

      preNode->next = curNode->next;
      ListNode* p = dummy;
      for (ListNode* p = dummy; p != head; p = p->next) {
        if (p->next->val < curNode->val) continue;
        curNode->next = p->next;
        p->next = curNode;
        break;
      }
    }

    head = dummy->next;
    delete dummy;
    return head;
  }
};
