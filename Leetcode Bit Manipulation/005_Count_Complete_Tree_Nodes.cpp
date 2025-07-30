class Solution {
  public:
  int countNodes(TreeNode *root) {
    if (root == NULL)
      return 0;

    TreeNode *left_run = root, *right_run = root;
    int left_depth = 0, right_depth = 0;

    while (left_run) {
      left_run = left_run->left;
      left_depth++;
    }

    while (right_run) {
      right_run = right_run->right;
      right_depth++;
    }

    if (left_depth == right_depth) {
      return (1 << left_depth) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};