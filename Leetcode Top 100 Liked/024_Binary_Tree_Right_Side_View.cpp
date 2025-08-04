// Using DFS
class Solution {
public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;

    function<void(TreeNode *, int)> DFS = [&](TreeNode *root, int level) -> void {
      if (root == NULL) {
        return;
      }
      if (ans.size() == level) {
        ans.push_back(root->val);
      }

      DFS(root->right, level + 1);
      DFS(root->left, level + 1);
    };

    DFS(root, 0);
    return ans;
  }
};

// Using BFS
class Solution {
  public:
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    if (root == NULL)
      return ans;

    queue<TreeNode *> queue;
    queue.push(root);

    while (!queue.empty()) {
      int size = queue.size();

      for (int i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();

        if (i == size - 1)
          ans.push_back(node->val);

        if (node->left)
          queue.push(node->left);
        if (node->right)
          queue.push(node->right);
      }
    }

    return ans;
  }
};