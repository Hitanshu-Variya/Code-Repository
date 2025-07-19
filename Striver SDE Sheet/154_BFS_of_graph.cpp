class Solution {
  public:
  vector<int> bfs(vector<vector<int>> &adj) {
    int size = adj.size();
    vector<int> ans;

    queue<int> queue;
    vector<bool> visited(size, false);
    queue.push(0);
    visited[0] = true;

    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();
      ans.push_back(node);

      for (int &neighbour : adj[node]) {
        if (!visited[neighbour]) {
          visited[neighbour] = true;
          queue.push(neighbour);
        }
      }
    }

    return ans;
  }
};