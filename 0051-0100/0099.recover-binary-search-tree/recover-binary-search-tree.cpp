class Solution {
 public:
  void recoverTree(TreeNode* root) {
    stack<TreeNode*> stack;
    TreeNode *x = NULL, *y = NULL, *pre = NULL;

    while (!stack.empty() || root != NULL) {
      while (root) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top();
      stack.pop();
      if (pre != NULL && pre->val > root->val) {
        y = root;
        if (!x)
          x = pre;
        else
          break;
      }
      pre = root;
      root = root->right;
    }
    swap(x->val, y->val);
  }
};
