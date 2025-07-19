class Solution {
  public:
  bool isCyclic(int V, vector<vector<int>> &edges) {
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    for (auto edge : edges) {
      int u = edge[0], v = edge[1];

      adj[u].push_back(v);
      indegree[v]++;
    }

    queue<int> queue;
    for (int i = 0; i < V; i++) {
      if (indegree[i] == 0) {
        queue.push(i);
      }
    }

    int visited = 0;
    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();
      visited++;

      for (int &neighbour : adj[node]) {
        indegree[neighbour]--;
        if (indegree[neighbour] == 0) {
          queue.push(neighbour);
        }
      }
    }

    return (visited != V);
  }
};