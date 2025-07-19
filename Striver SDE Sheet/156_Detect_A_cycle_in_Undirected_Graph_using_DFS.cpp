class Solution {
  public:
  bool isCycle(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for (auto edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<bool> visited(V, false);

    function<bool(int, int)> hasCycle = [&](int node, int parent) -> bool {
      visited[node] = true;

      for (int &neighbour : adj[node]) {
        if (visited[neighbour] && neighbour != parent) {
          return true;
        }
        if (!visited[neighbour] && hasCycle(neighbour, node)) {
          return true;
        }
      }

      return false;
    };

    for (int i = 0; i < V; i++) {
      if (!visited[i] && hasCycle(i, -1)) {
        return true;
      }
    }

    return false;
  }
};