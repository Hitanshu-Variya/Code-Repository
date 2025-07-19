class Solution {
  public:
  vector<int> dfs(vector<vector<int>> &adj) {
    int size = adj.size();
    vector<int> ans;
    vector<bool> visited(size, false);

    function<void(int)> DFS = [&](int node) -> void {
      visited[node] = true;
      ans.push_back(node);

      for (int &neighbour : adj[node]) {
        if (!visited[neighbour]) {
          DFS(neighbour);
        }
      }
    };

    DFS(0);
    return ans;
  }
};