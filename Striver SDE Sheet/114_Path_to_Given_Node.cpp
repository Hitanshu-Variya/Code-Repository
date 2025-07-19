vector<int> Solution::solve(TreeNode *A, int B) {
  vector<int> path, trace;

  function<void(TreeNode *)> solver = [&](TreeNode *root) -> void {
    if (root == NULL) {
      return;
    }

    if (root->val == B) {
      trace.push_back(root->val);
      path = trace;
      return;
    }

    trace.push_back(root->val);

    solver(root->left);
    solver(root->right);

    trace.pop_back();
  };

  solver(A);
  return path;
}
