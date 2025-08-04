class Solution {
  public:
  int kthSmallest(TreeNode *root, int k) {
    int count = 0;
    int ans = -1;

    function<void(TreeNode *)> inorder = [&](TreeNode *root) -> void {
      if (root == NULL)
        return;

      inorder(root->left);
      count++;
      if (count == k) ans = root->val;
      inorder(root->right);
    };

    inorder(root);
    return ans;
  }
};