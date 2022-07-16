/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    int res = f(root);
    if (res == -1) return false;
    return true;
  }
  int f(TreeNode* root) {
    if (!root) return 0;

    int left = f(root->left);
    int right = f(root->right);
    if (abs(left - right) > 1 || left == -1 || right == -1) return -1;

    return max(left, right) + 1;
  }
};
