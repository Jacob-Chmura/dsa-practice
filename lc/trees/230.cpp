class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    vector<int> sortedNodes;
    dfs(root, sortedNodes);
    return sortedNodes[k - 1];
  }

private:
  void dfs(TreeNode *root, vector<int> &nodes) {
    if (root != nullptr) {
      dfs(root->left, nodes);
      nodes.push_back(root->val);
      dfs(root->right, nodes);
    }
  }
};
