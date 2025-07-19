class Solution {
  private:
  int solver(TreeNode *root, bool &status) {
    if (root == NULL) {
      return 0;
    }

    int LeftDepth = solver(root->left, status);
    int RightDepth = solver(root->right, status);

    status &= (abs(LeftDepth - RightDepth) <= 1);
    return 1 + max(LeftDepth, RightDepth);
  }

  public:
  bool isBalanced(TreeNode *root) {
    bool status = true;
    solver(root, status);

    return status;
  }
};