class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    return inorder(root, result);
  }

private:
  vector<int> inorder(TreeNode *root, vector<int> &tmp) {
    if (root == nullptr)
      return tmp;
    tmp = inorder(root->left, tmp);
    tmp.push_back(root->val);
    tmp = inorder(root->right, tmp);
    return tmp;
  }
};
