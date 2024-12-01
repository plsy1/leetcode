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
  vector<vector<int>> res;
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    f(root, 0);
    return vector<vector<int>>(res.rbegin(), res.rend());
  }
  void f(TreeNode* node, int idx) {
    if (!node) return;
    if (res.size() == idx) res.push_back({});
    res[idx].push_back(node->val);
    f(root->left, idx + 1);
    f(root->right, idx + 1);
  }
};
