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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return 0;
        ListNode* dummy = head->next;
        ListNode* l = head, *r = head->next;
        while(r && r->next) {
            l->next = r->next;
            r->next = r->next->next;
            l=l->next;
            r=r->next;
        }
        l->next = dummy;
        return head;
    }
};
