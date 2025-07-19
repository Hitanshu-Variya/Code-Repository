class Solution {
  private:
  void getInorder(TreeNode *root, vector<int> &inorder) {
    if (root == NULL) {
      return;
    }

    getInorder(root->left, inorder);
    inorder.push_back(root->val);
    getInorder(root->right, inorder);
  }

  public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> inorder;
    getInorder(root, inorder);

    return inorder;
  }
};