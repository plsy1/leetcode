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
  int sumOfLeftLeaves(TreeNode* root) {
    dfs(root);
    return res;
  }

 private:
  int res;
  void dfs(TreeNode* root) {
    if (!root) return;
    if (root->left && !root->left->left && !root->left->right) {
      res += root->left->val;
    }
    dfs(root->left);
    dfs(root->right);
  }
};
