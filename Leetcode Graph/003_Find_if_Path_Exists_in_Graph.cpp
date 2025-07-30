class Solution {
  public:
  bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
    vector<bool> visited(n, false);
    unordered_map<int, vector<int>> adj;
    for (auto itr : edges) {
      adj[itr[0]].push_back(itr[1]);
      adj[itr[1]].push_back(itr[0]);
    }

    queue<int> queue;
    queue.push(source);
    visited[source] = true;

    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();
      if (node == destination) {
        return true;
      }

      for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
          queue.push(neighbour);
          visited[neighbour] = true;
        }
      }
    }

    return false;
  }
};