#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> result;
    queue<TreeNode *> q;
    if (root != nullptr)
      q.push(root);

    while (!q.empty()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        TreeNode *node = q.front();
        q.pop();
        if (i == 0)
          result.push_back(node->val);
        if (node->right != nullptr)
          q.push(node->right);
        if (node->left != nullptr)
          q.push(node->left);
      }
    }
    return result;
  }
};
