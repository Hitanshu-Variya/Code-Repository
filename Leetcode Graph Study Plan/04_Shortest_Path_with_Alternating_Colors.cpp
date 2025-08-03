class Solution {
  public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
    vector<vector<int>> adjRed(n), adjBlue(n);

    for (auto &edge : redEdges) {
      int u = edge[0], v = edge[1];
      adjRed[u].push_back(v);
    }

    for (auto &edge : blueEdges) {
      int u = edge[0], v = edge[1];
      adjBlue[u].push_back(v);
    }

    vector<int> ans(n, INT_MAX);
    vector<vector<bool>> visited(n, vector<bool>(2, false));
    queue<vector<int>> queue;
    queue.push({0, 0, 0});
    queue.push({0, 1, 0});
    visited[0][0] = visited[0][1] = true;

    while (!queue.empty()) {
      int node = queue.front()[0];
      int color = queue.front()[1];
      int distance = queue.front()[2];
      queue.pop();

      ans[node] = min(ans[node], distance);

      if (color == 0) {
        for (int &neighbour : adjBlue[node]) {
          if (!visited[neighbour][1]) {
            visited[neighbour][1] = true;
            queue.push({neighbour, 1, distance + 1});
          }
        }
      }

      if (color == 1) {
        for (int &neighbour : adjRed[node]) {
          if (!visited[neighbour][0]) {
            visited[neighbour][0] = true;
            queue.push({neighbour, 0, distance + 1});
          }
        }
      }
    }

    for (int &distance : ans) {
      if (distance == INT_MAX) {
        distance = -1;
      }
    }

    return ans;
  }
};