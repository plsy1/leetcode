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
struct cmp {
    bool operator()(ListNode * a, ListNode * b) {
        return a->val > b->val;
    }
};
ListNode * mergeKLists(vector<ListNode *>& lists) {
    priority_queue<ListNode *, vector<ListNode *>, cmp> pQueue;

    for (auto s : lists) {
        if (s) pQueue.push(s);
    }
    ListNode dummy(-1);
    ListNode * p = &dummy;

    while (!pQueue.empty()) {
        ListNode * top = pQueue.top();
        pQueue.pop();
        p->next = top; p = p = top;
        if (top->next) pQueue.push(top->next);
    }
    return dummy.next;
}
};
