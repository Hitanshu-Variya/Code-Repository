class Solution {
  public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (root == NULL || root == p || root == q) {
      return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    if (left != NULL && right != NULL) {
      return root;
    }

    return ((left != NULL) ? left : right);
  }
};