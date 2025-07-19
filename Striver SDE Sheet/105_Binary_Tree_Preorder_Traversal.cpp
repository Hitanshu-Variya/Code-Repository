class Solution {
  private:
  void getPreorder(TreeNode *root, vector<int> &preorder) {
    if (root == NULL) {
      return;
    }

    preorder.push_back(root->val);
    getPreorder(root->left, preorder);
    getPreorder(root->right, preorder);
  }

  public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> preorder;
    getPreorder(root, preorder);

    return preorder;
  }
};