/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 空间复杂度O(1)进阶解法
class Solution {
public:
ListNode * removeDuplicateNodes(ListNode * head) {
    if (head == NULL) return head;
    ListNode * cur = head;

    while (cur) {
        ListNode * temp = cur;
        while (temp->next) {
            if (temp->next->val == cur->val) temp->next = temp->next->next;
            else temp = temp->next;
        }
        cur = cur->next;
    }
    return head;
}
};

// 非进阶解法
class Solution {
public:

ListNode * removeDuplicateNodes(ListNode * head) {

    if (head == nullptr)
        return head;

    unordered_set<int> set;

    set.insert(head->val);
    ListNode * prev = head;

    while (prev->next) {
        if (set.find(prev->next->val) != set.end()) {
            prev->next = prev->next->next;
        } else {
            set.insert(prev->next->val);
            prev = prev->next;
        }
    }
    return head;
}
};
