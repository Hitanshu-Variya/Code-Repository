class Solution {
  public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == NULL)
      return ans;

    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      int size = queue.size();
      vector<int> temp_ans;

      for (int i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();
        temp_ans.push_back(node->val);

        if (node->left)
          queue.push(node->left);
        if (node->right)
          queue.push(node->right);
      }

      ans.push_back(temp_ans);
    }

    return ans;
  }
};