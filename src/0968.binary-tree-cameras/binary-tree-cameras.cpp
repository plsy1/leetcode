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
  enum State { NEEDED, COVERED, CAMERA };
  int res = 0;
  int minCameraCover(TreeNode* rt) {
    if (dfs(rt) == NEEDED) ++res;
    return res;
  }
  State dfs(TreeNode* rt) {
    if (!rt) return COVERED;
    auto l = dfs(rt->left), r = dfs(rt->right);
    if (l == NEEDED || r == NEEDED) {
      ++res;
      return CAMERA;
    }
    if (l == CAMERA || r == CAMERA) return COVERED;
    return NEEDED;
  }
};
