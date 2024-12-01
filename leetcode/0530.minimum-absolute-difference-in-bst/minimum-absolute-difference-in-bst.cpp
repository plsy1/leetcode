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
    int getMinimumDifference(TreeNode* root) {
      dfs(root);
      return res;
    }
private:
  TreeNode* pre = nullptr;
  int res = INT_MAX;
  void dfs(TreeNode* root) {
    if(!root) return;
    dfs(root->left);
    if(pre) res = min(root->val - pre->val,res);
    pre = root;
    dfs(root->right);
  }
};
