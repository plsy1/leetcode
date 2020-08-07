/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int n = 0;
  int res;
  int kthSmallest(TreeNode* root, int k) {
    f(root, k);
    return res;
  }

  void f(TreeNode* root, int k) {
    if (!root) return;
    f(root->left, k);
    n++;
    if (n == k) res = root->val;
    f(root->right, k);
  }
};
