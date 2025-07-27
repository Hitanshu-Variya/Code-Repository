class Solution {
  private:
  TreeNode *adjust(TreeNode *rightTree, int root) {
    if (rightTree == NULL)
      return NULL;

    TreeNode *node = new TreeNode(rightTree->val + root);
    node->left = adjust(rightTree->left, root);
    node->right = adjust(rightTree->right, root);

    return node;
  }

  public:
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0)
      return vector<TreeNode *>();

    vector<vector<TreeNode *>> dp(n + 1);
    dp[0].push_back(NULL);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= i; j++) {
        for (TreeNode *leftTree : dp[j - 1]) {
          for (TreeNode *rightTree : dp[i - j]) {
            TreeNode *root = new TreeNode(j);
            root->left = leftTree;
            root->right = adjust(rightTree, j);
            dp[i].push_back(root);
          }
        }
      }
    }

    return dp[n];
  }
};