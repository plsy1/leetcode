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
  TreeNode* convertBST(TreeNode* root) {
    if (root) {
      convertBST(root->right);
      val += root->val;
      root->val = val;
      convertBST(root->left);
    }
    return root;
  }

 private:
  int val = 0;
};
