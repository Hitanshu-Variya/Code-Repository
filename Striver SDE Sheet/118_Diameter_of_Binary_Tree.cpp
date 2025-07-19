class Solution {
  private:
  int solver(TreeNode *root, int &diameter) {
    if (root == NULL) {
      return 0;
    }

    int LeftSubTree = solver(root->left, diameter);
    int RightSubTree = solver(root->right, diameter);

    diameter = max(diameter, LeftSubTree + RightSubTree);
    return 1 + max(LeftSubTree, RightSubTree);
  }

  public:
  int diameterOfBinaryTree(TreeNode *root) {
    int diameter = 0;
    solver(root, diameter);

    return diameter;
  }
};