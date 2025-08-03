class Solution {
  public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
    vector<vector<int>> adj(n);
    for (auto &connection : connections) {
      int u = connection[0], v = connection[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<vector<int>> bridges;
    int timer = 1;
    vector<bool> visited(n, false);
    vector<int> timeIn(n), low(n);

    function<void(int, int)> DFS = [&](int node, int parent) -> void {
      visited[node] = true;
      timeIn[node] = low[node] = timer;
      timer++;

      for (int &neighbour : adj[node]) {
        if (neighbour == parent) {
          continue;
        }

        if (!visited[neighbour]) {
          DFS(neighbour, node);
          low[node] = min(low[node], low[neighbour]);

          if (low[neighbour] > timeIn[node]) {
            bridges.push_back({node, neighbour});
          }
        } else {
          low[node] = min(low[node], low[neighbour]);
        }
      }
    };

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        DFS(i, -1);
      }
    }

    return bridges;
  }
};