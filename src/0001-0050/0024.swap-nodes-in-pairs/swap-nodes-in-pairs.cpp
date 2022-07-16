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
ListNode * swapPairs(ListNode * head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode * next = head->next;

    next->next = swapPairs(next->next);

    head->next = next->next;
    next->next = head;

    return next;

}
};
