class Solution {
  public:
  int minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<int>> adj(n), rev_graph(n);
    for (auto &connection : connections) {
      int u = connection[0], v = connection[1];
      adj[u].push_back(v);
      rev_graph[v].push_back(u);
    }

    vector<bool> visited(n, false);
    int count = 0;

    function<void(int)> BFS = [&](int source) -> void {
      queue<int> queue;
      queue.push(source);
      visited[source] = true;

      while (!queue.empty()) {
        int node = queue.front();
        queue.pop();

        for (int &neighbour : adj[node]) {
          if (!visited[neighbour]) {
            count++;
            queue.push(neighbour);
            visited[neighbour] = true;
          }
        }

        for (int &neighbour : rev_graph[node]) {
          if (!visited[neighbour]) {
            queue.push(neighbour);
            visited[neighbour] = true;
          }
        }
      }
    };

    BFS(0);
    return count;
  }
};