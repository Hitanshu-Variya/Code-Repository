class Solution {
  public:
  bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    for (auto edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
    }

    vector<bool> visited(V, false);
    vector<bool> recursionStack(V, false);

    function<bool(int)> hasCycle = [&](int node) -> bool {
      if (recursionStack[node])
        return true;
      if (visited[node])
        return false;

      recursionStack[node] = true;
      visited[node] = true;

      for (int &neighbour : adj[node]) {
        if (hasCycle(neighbour)) {
          return true;
        }
      }

      recursionStack[node] = false;
      return false;
    };

    for (int i = 0; i < V; i++) {
      if (!visited[i] && hasCycle(i)) {
        return true;
      }
    }

    return false;
  }
};