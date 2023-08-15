#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    // just bfs
    queue<TreeNode *> q;
    if (root != nullptr)
      q.push(root);

    vector<vector<int>> result;
    while (!q.empty()) {
      vector<int> level_result;
      int n = q.size();
      for (int i = 0; i < n; ++i) {
        TreeNode *node = q.front();
        q.pop();
        level_result.push_back(node->val);
        if (node->left != nullptr)
          q.push(node->left);
        if (node->right != nullptr)
          q.push(node->right);
      }
      result.push_back(level_result);
    }
    return result;
  }
};
