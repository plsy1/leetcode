class Solution {
public:
ListNode * removeNthFromEnd(ListNode * head, int n) {
    int len = 1;
    ListNode * res = head;

    while (res->next != NULL) {
        res = res->next;
        ++len;
    }
    if (n == len) return head->next;
    int fromBegin = len - 1 - n;
    ListNode * p = head, * q = head->next;

    while (fromBegin) {
        p = p->next;
        q = q->next;
        --fromBegin;
    }
    p->next = q->next;
    return head;
}
};
