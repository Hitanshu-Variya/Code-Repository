class Solution {
  private:
  vector<int> DFS(TreeNode *root) {
    if (root == NULL) {
      return {0, 0};
    }

    vector<int> left = DFS(root->left);
    vector<int> right = DFS(root->right);

    vector<int> ans(2, 0);
    ans[0] = root->val + left[1] + right[1];
    ans[1] = max(left[0], left[1]) + max(right[0], right[1]);

    return ans;
  }

  public:
  int rob(TreeNode *root) {
    vector<int> ans = DFS(root);
    return max(ans[0], ans[1]);
  }
};