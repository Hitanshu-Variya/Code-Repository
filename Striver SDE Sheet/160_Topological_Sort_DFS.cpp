class Solution {
  public:
  vector<int> topoSort(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    vector<bool> visited(V, false);
    vector<int> ans;

    for (auto edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
    }

    function<void(int)> DFS = [&](int node) -> void {
      visited[node] = true;

      for (int &neighbour : adj[node]) {
        if (!visited[neighbour]) {
          DFS(neighbour);
        }
      }

      ans.push_back(node);
    };

    for (int i = 0; i < V; i++) {
      if (!visited[i]) {
        DFS(i);
      }
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};