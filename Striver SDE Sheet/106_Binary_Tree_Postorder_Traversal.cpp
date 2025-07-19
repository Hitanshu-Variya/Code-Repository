class Solution {
  private:
  void getPostorder(TreeNode *root, vector<int> &postorder) {
    if (root == NULL) {
      return;
    }

    getPostorder(root->left, postorder);
    getPostorder(root->right, postorder);
    postorder.push_back(root->val);
  }

  public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> postorder;
    getPostorder(root, postorder);

    return postorder;
  }
};