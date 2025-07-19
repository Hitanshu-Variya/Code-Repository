class Solution {
  private:
  int ans = INT_MIN;
  int solver(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }

    int leftMaxSum = max(0, solver(root->left));
    int rightMaxSum = max(0, solver(root->right));

    ans = max(ans, leftMaxSum + rightMaxSum + root->val);
    return max(leftMaxSum, rightMaxSum) + root->val;
  }

  public:
  int maxPathSum(TreeNode *root) {
    solver(root);
    return ans;
  }
};