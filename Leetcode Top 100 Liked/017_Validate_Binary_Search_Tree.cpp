class Solution {
  private:
  bool isBST(TreeNode *root, long long left, long long right) {
    if (root == NULL) {
      return true;
    }

    if (root->val < right && root->val > left)
      return isBST(root->left, left, root->val) && isBST(root->right, root->val, right);
    else
      return false;
  }

  public:
  bool isValidBST(TreeNode *root) { 
    return isBST(root, LLONG_MIN, LLONG_MAX); 
  }
};