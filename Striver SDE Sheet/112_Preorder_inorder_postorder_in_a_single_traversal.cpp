vector<vector<int>> getTreeTraversal(TreeNode *root) {
  vector<vector<int>> ans(3);

  stack<pair<TreeNode *, int>> st;
  st.push({root, 1});

  while (!st.empty()) {
    pair<TreeNode *, int> node = st.top();
    st.pop();

    TreeNode *head = node.first;
    int type = node.second;

    if (type == 1) {
      ans[1].push_back(head->data);
      st.push({head, 2});

      if (head->left) {
        head = head->left;
        st.push({head, 1});
      }
    } else if (type == 2) {
      ans[0].push_back(head->data);
      st.push({head, 3});

      if (head->right) {
        head = head->right;
        st.push({head, 1});
      }
    } else {
      ans[2].push_back(head->data);
    }
  }

  return ans;
}