class Solution {
  private:
  void buildGraph(TreeNode *node, TreeNode *parent, unordered_map<TreeNode *, vector<TreeNode *>> &graph) {
    if (node == nullptr)
      return;

    if (parent) {
      graph[node].push_back(parent);
      graph[parent].push_back(node);
    }

    buildGraph(node->left, node, graph);
    buildGraph(node->right, node, graph);
  }

  public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    unordered_map<TreeNode *, vector<TreeNode *>> graph;
    buildGraph(root, nullptr, graph);

    vector<int> ans;
    unordered_set<TreeNode *> visited;
    queue<TreeNode *> queue;
    queue.push(target);
    visited.insert(target);

    int level = 0;
    while (!queue.empty()) {
      if (level == k)
        break;
      int size = queue.size();

      for (int i = 0; i < size; i++) {
        TreeNode *node = queue.front();
        queue.pop();

        for (TreeNode *neighbour : graph[node]) {
          if (!visited.count(neighbour)) {
            visited.insert(neighbour);
            queue.push(neighbour);
          }
        }
      }

      level++;
    }

    while (!queue.empty()) {
      TreeNode *node = queue.front();
      queue.pop();
      ans.push_back(node->val);
    }

    return ans;
  }
};