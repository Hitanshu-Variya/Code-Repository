class Solution {
  public:
  bool isBipartite(vector<vector<int>> &graph) {
    int size = graph.size();
    vector<int> color(size, -1);

    function<bool(int, int)> DFS = [&](int node, int parent) -> bool {
      color[node] = (parent == -1) ? 0 : 1 - color[parent];

      for (int &neighbour : graph[node]) {
        if (color[neighbour] == color[node]) {
          return false;
        }
        if (color[neighbour] == -1 && !DFS(neighbour, node)) {
          return false;
        }
      }

      return true;
    };

    for (int i = 0; i < size; i++) {
      if (color[i] == -1 && !DFS(i, -1)) {
        return false;
      }
    }

    return true;
  }
};