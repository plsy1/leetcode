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
  vector<int> findMode(TreeNode* root) {
    if (!root) return {};
    f(root);
    pair<int, int> mx(0, 0);
    set<int> res;
    for (auto p : m)
      if (p.second > mx.second) mx = p;
    res.insert(mx.first);
    for (auto p : m)
      if (p.second == mx.second) res.insert(p.first);
    return {res.begin(), res.end()};
  }

 private:
  unordered_map<int, int> m;
  void f(TreeNode* root) {
    if (!root) return;
    ++m[root->val];
    f(root->left);
    f(root->right);
  }
};

/* use morris traverse
/- O(n) time complexity and O(1) Space complexity
*/

class Solution {
 public:
  vector<int> findMode(TreeNode* root) {
    TreeNode *cur = root, *pre = nullptr;
    while (cur) {
      if (!cur->left) {
        addMax(cur->val);
        cur = cur->right;
        continue;
      }
      pre = cur->left;
      while (pre->right && pre->right != cur) pre = pre->right;

      if (!pre->right) {
        pre->right = cur;
        cur = cur->left;
      } else {
        pre->right = nullptr;
        addMax(cur->val);
        cur = cur->right;
      }
    }
    return res;
  }
  void addMax(int n) {
    if (n == base)
      ++count;
    else {
      count = 1;
      base = n;
    }
    if (count == maxCount) res.push_back(base);
    if (count > maxCount) {
      maxCount = count;
      res = {base};
    }
  }

 private:
  int base, count, maxCount;
  vector<int> res;
};
