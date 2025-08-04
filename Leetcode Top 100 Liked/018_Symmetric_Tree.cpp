class Solution {
  private:
  bool isMirror(TreeNode *T1, TreeNode *T2) {
    if (T1 == NULL && T2 == NULL) return true;
    if (T1 == NULL || T2 == NULL) return false;

    return (T1->val == T2->val && isMirror(T1->left, T2->right) && isMirror(T1->right, T2->left));
  }

  public:
  bool isSymmetric(TreeNode *root) { 
    return isMirror(root->left, root->right); 
  }
};