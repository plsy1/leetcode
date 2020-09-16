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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* p = dummy;

    while (p->next && p->next->next) {
      if (p->next->val == p->next->next->val) {
        ListNode* tmp = p->next;
        while (tmp && tmp->next && tmp->val == tmp->next->val) tmp = tmp->next;
        p->next = tmp->next;
      } else
        p = p->next;
    }
    return dummy->next;
  }
};

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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    if (head->val == head->next->val) {
      while (head && head->next && head->val == head->next->val)
        head = head->next;
      return deleteDuplicates(head->next);
    } else {
      head->next = deleteDuplicates(head->next);
      return head;
    }
  }
};
