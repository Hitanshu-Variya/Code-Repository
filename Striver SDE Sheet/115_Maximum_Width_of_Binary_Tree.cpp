using i64 = long long int;
class Solution {
  public:
  int widthOfBinaryTree(TreeNode *root) {
    i64 width = 0;
    if (root == NULL) {
      return width;
    }

    queue<pair<TreeNode *, i64>> queue;
    queue.push({root, 0});

    while (!queue.empty()) {
      int size = queue.size();
      i64 min_index = queue.front().second, max_index = -1;

      for (int i = 0; i < size; i++) {
        pair<TreeNode *, i64> node = queue.front();
        queue.pop();

        TreeNode *head = node.first;
        max_index = node.second;

        if (head->left)
          queue.push({head->left, 2 * (max_index - min_index)});
        if (head->right)
          queue.push({head->right, 2 * (max_index - min_index) + 1});
      }

      width = max(width, max_index - min_index + 1);
    }

    return static_cast<int>(width);
  }
};