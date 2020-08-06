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
  pair<int, int> dfs(TreeNode *root) {
    if (root == NULL) return {0, 0};

    auto left = dfs(root->left);
    auto right = dfs(root->right);
    return make_pair(
        max(left.first, left.second) + max(right.first, right.second),
        left.first + right.first + root->val);
  }
  int rob(TreeNode *root) {
    pair<int, int> res = dfs(root);
    return max(res.first, res.second);
  }
};
