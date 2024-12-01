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
  TreeNode* invertTree(TreeNode* root) {
    dfs(root);
    return root;
  }
  void dfs(TreeNode* root) {
    if (!root) return;
    swap(root->left, root->right);
    dfs(root->left);
    dfs(root->right);
  }
};
