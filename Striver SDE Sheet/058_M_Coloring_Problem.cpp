class Solution {
  public:
  bool graphColoring(int v, vector<vector<int>> &edges, int m) {
    vector<vector<int>> adj(v);
    for (auto &edge : edges) {
      int a = edge[0], b = edge[1];
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    vector<int> color(v, -1);
    function<bool(int, int)> isValid = [&](int node, int nodeColor) -> bool {
      for (int &neighbour : adj[node]) {
        if (color[neighbour] == nodeColor)
          return false;
      }

      return true;
    };

    function<bool(int)> DFS = [&](int node) -> bool {
      if (node == v)
        return true;

      for (int i = 1; i <= m; i++) {
        if (isValid(node, i)) {
          color[node] = i;
          if (DFS(node + 1)) {
            return true;
          }
          color[node] = -1;
        }
      }

      return false;
    };

    return DFS(0);
  }
};