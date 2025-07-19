class Solution {
  public:
  bool isBipartite(vector<vector<int>> &graph) {
    int size = graph.size();
    vector<int> color(size, -1);

    function<bool(int)> BFS = [&](int node) -> bool {
      queue<int> queue;
      queue.push(node);
      color[node] = 0;

      while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        for (int &neighbour : graph[node]) {
          if (color[neighbour] == color[node]) {
            return false;
          }
          if (color[neighbour] == -1) {
            color[neighbour] = 1 - color[node];
            queue.push(neighbour);
          }
        }
      }

      return true;
    };

    for (int i = 0; i < size; i++) {
      if (color[i] == -1 && !BFS(i)) {
        return false;
      }
    }

    return true;
  }
};