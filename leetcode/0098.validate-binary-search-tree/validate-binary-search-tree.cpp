/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// wrong answer
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (!root) return true;
    if (root->left->val > root->val) return false;
    if (root->right->val < root->val) return false;
    return isValidBST(root->right) && isValidBST(root->left);
  }
};

class Solution {
 public:
  bool isValidBST(TreeNode* root) { return f(root, INT_MIN, INT_MAX); }
  bool f(TreeNode* root, long min, long max) {
    if (!root) return true;
    if (root->val < min || root->val > max) return false;
    return f(root->left, min, root->val - 1l) &&
           f(root->right, root->val + 1l, max);
  }
};
