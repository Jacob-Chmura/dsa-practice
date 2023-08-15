class Solution {
public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0 || inorder.size() == 0)
      return nullptr;
    TreeNode *root = new TreeNode(preorder[0]);

    int i = 0;
    while (inorder[i] != preorder[0])
      ++i;

    vector<int> preorderRight(preorder.begin() + i + 1, preorder.end());
    vector<int> inorderRight(inorder.begin() + i + 1, inorder.end());
    vector<int> preorderLeft(preorder.begin() + 1, preorder.begin() + i + 1);
    vector<int> inorderLeft(inorder.begin(), inorder.begin() + i);
    root->right = buildTree(preorderRight, inorderRight);
    root->left = buildTree(preorderLeft, inorderLeft);
    return root;
  }
};
