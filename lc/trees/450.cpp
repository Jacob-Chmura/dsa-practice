class Solution {
public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr)
      return root;
    if (root->val < key) {
      root->right = deleteNode(root->right, key);
    } else if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else {
      if (root->left == nullptr) {
        return root->right;
      } else if (root->right == nullptr) {
        return root->left;
      }

      // we have two children
      TreeNode *min_node = findMin(root->right);
      root->val = min_node->val;
      root->right = deleteNode(root->right, min_node->val);
    }
    return root;
  }

private:
  TreeNode *findMin(TreeNode *root) {
    TreeNode *curr = root;
    while (curr && curr->left)
      curr = curr->left;
    return curr;
  }
};
