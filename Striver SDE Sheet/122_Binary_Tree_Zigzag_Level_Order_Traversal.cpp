class Solution {
  public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    if (root == NULL)
      return ans;

    deque<TreeNode *> deque;
    deque.push_back(root);
    bool to_reverse = false;

    while (!deque.empty()) {
      int size = deque.size();
      vector<int> temp_ans;

      for (int i = 0; i < size; i++) {
        if (!to_reverse) {
          TreeNode *node = deque.front();
          deque.pop_front();
          temp_ans.push_back(node->val);

          if (node->left) deque.push_back(node->left);
          if (node->right) deque.push_back(node->right);
        } 
        else {
          TreeNode *node = deque.back();
          deque.pop_back();
          temp_ans.push_back(node->val);

          if (node->right) deque.push_front(node->right);
          if (node->left) deque.push_front(node->left);
        }
      }

      ans.push_back(temp_ans);
      to_reverse = !to_reverse;
    }

    return ans;
  }
};