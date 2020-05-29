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
// 别写反了
    if (head == NULL || head->next == NULL) return head;
    ListNode next = head.next;

// 连接前一组的尾部与后一组的头部
    next.next = swapPairs(next.next);
// 交换两节点位置
    head.next = next.next;
    next.next = head;

    return next;

}
};
