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
  unordered_map<int, int> map;
  int idx = 0;
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i != inorder.size(); ++i) map[inorder[i]] = i;
    return dfs(preorder, 0, preorder.size() - 1);
  }
  TreeNode* dfs(vector<int>& pre, int l, int r) {
    if (l > r) return NULL;
    int i = map[pre[idx]];
    TreeNode* root = new TreeNode(pre[idx++]);
    root->left = dfs(pre, l, i - 1);
    root->right = dfs(pre, i + 1, r);
    return root;
  }
};
