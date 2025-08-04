class Solution {
  public:
  TreeNode *invertTree(TreeNode *root) {
    if (root->left == NULL && root->right == NULL) {
      return root;
    }

    TreeNode *left_side = invertTree(root->left);
    TreeNode *right_side = invertTree(root->right);

    root->left->val = right_side->val;
    root->right->val = left_side->val;

    return root;
  }
};