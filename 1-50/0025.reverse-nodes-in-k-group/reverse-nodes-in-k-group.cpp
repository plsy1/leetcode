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
ListNode * reverseKGroup(ListNode * head, int k) {
    int c = 0;
    ListNode * p = head;

    while (p != NULL && c != k) {
        p = p->next;
        ++c;
    }
    if (c < k) return head;

    ListNode * pre = NULL;
    ListNode * q = head;

    while (q != p) {
        ListNode * temp = q->next;
        q->next = pre;
        pre = q;
        q = temp;
    }
    head->next = reverseKGroup(q, k);
    return pre;
} // reverseKGroup
};
