class Solution {
  public:
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    map<int, vector<pair<int, int>>> hash_map;
    queue<tuple<TreeNode *, int, int>> queue;
    queue.push({root, 0, 0});

    while (!queue.empty()) {
      auto [node, row, column] = queue.front();
      queue.pop();

      hash_map[column].push_back({row, node->val});

      if (node->left) {
        queue.push({node->left, row + 1, column - 1});
      }

      if (node->right) {
        queue.push({node->right, row + 1, column + 1});
      }
    }

    vector<vector<int>> ans;
    for (auto [column, sequence] : hash_map) {
      sort(sequence.begin(), sequence.end());
      vector<int> nums;

      for (auto itr : sequence) {
        nums.push_back(itr.second);
      }

      ans.push_back(nums);
    }

    return ans;
  }
};