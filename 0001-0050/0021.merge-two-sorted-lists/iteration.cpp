ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  ListNode* res = new ListNode(-1);
  ListNode* prev = res; //用于保存头节点的位置

  while(l1 != NULL && l2 != NULL) {
    if(l1->val <= l2->val) {
      res->next = l1;
      l1 = l1->next;
    }
    else {
      res->next = l2;
      l2 = l2->next;
    }
    res = res->next;
  }
  res->next = l1->next != NULL ? l1 : l2;
  return prev->next;
}
