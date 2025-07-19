class Solution {
  public:
  vector<int> topView(Node *root) {
    vector<int> ans;
    if (root == NULL) {
      return ans;
    }

    map<int, int> hash_map;
    queue<pair<Node *, int>> queue;
    queue.push({root, 0});

    while (!queue.empty()) {
      pair<Node *, int> node = queue.front();
      queue.pop();

      Node *head = node.first;
      int level = node.second;

      if (hash_map.find(level) == hash_map.end()) {
        hash_map[level] = head->data;
      }

      if (head->left) {
        queue.push({head->left, level - 1});
      }

      if (head->right) {
        queue.push({head->right, level + 1});
      }
    }

    for (auto &itr : hash_map) {
      ans.push_back(itr.second);
    }

    return ans;
  }
};