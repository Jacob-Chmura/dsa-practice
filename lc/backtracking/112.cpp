class Solution {
public:
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (root == nullptr)
      return false;
    if (root->left == nullptr && root->right == nullptr) {
      return root->val == targetSum;
    }
    if (root->left && hasPathSum(root->left, targetSum - root->val)) {
      return true;
    }
    if (root->right && hasPathSum(root->right, targetSum - root->val)) {
      return true;
    }
    return false;
  }
};
