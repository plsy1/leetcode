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
  vector<vector<int>> levelOrder(TreeNode* root) {
    f(root, 0);
    return res;
  }
  void f(TreeNode* root, int i) {
    if (!root) return;
    if (res.size() == i) res.resize(i + 1);
    res[i].push_back(root->val);
    f(root->left, i + 1);
    f(root->right, i + 1);
  }
};
