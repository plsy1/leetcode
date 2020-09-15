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
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* tmp = root;

    while (!s.empty() || tmp) {
      while (tmp) {
        s.push(tmp);
        tmp = tmp->left;
      }
      TreeNode* node = s.top();
      s.pop();
      res.push_back(node->val);
      tmp = node->right;
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
  vector<int> inorderTraversal(TreeNode* root) {
    if (root) {
      inorderTraversal(root->left);
      res.push_back(root->val);
      inorderTraversal(root->right);
    }
    return res;
  }
};
