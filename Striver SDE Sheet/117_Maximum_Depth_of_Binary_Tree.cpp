class Solution {
  public:
  int maxDepth(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }

    int left_depth = maxDepth(root->left);
    int right_depth = maxDepth(root->right);

    return max(left_depth, right_depth) + 1;
  }
};