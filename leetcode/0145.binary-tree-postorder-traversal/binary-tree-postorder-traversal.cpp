/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stack;
    if (!root) return {};
    stack.push(root);
    while (!stack.empty()) {
      TreeNode* node = stack.top();
      stack.pop();
      res.push_back(node->val);
      if (node->left) stack.push(node->left);
      if (node->right) stack.push(node->right);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> res;
  vector<int> postorderTraversal(TreeNode* root) {
    if (root) {
      postorderTraversal(root->left);
      postorderTraversal(root->right);
      res.push_back(root->val);
    }
    return res;
  }
};
