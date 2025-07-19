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

    function<bool(int)> hasCycle = [&](int start) -> bool {
      queue<pair<int, int>> queue;
      queue.push({start, -1});
      visited[start] = true;

      while (!queue.empty()) {
        int node = queue.front().first;
        int parent = queue.front().second;
        queue.pop();

        for (int &neighbour : adj[node]) {
          if (visited[neighbour] && neighbour != parent)
            return true;
          if (!visited[neighbour]) {
            visited[neighbour] = true;
            queue.push({neighbour, node});
          }
        }
      }

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