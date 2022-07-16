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
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    stack<TreeNode*> stack;
    vector<int> res;

    stack.push(root);
    while (!stack.empty()) {
      TreeNode* node = stack.top();
      res.push_back(node->val);
      stack.pop();
      if (node->right) stack.push(node->right);
      if (node->left) stack.push(node->left);
    }
    return res;
  }
};

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
  vector<int> res;
  vector<int> preorderTraversal(TreeNode* root) {
    if (root) {
      res.push_back(root->val);
      preorderTraversal(root->left);
      preorderTraversal(root->right);
    }
    return res;
  }
};
