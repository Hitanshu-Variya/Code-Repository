class Solution {
  public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    if (n == 1)
      return {0};

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for (auto edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
      indegree[u]++;
      indegree[v]++;
    }

    queue<int> queue;
    for (int i = 0; i < n; i++) {
      if (indegree[i] == 1) {
        queue.push(i);
      }
    }

    int remaining = n;
    while (remaining > 2) {
      int size = queue.size();
      remaining -= size;

      for (int i = 0; i < size; i++) {
        int node = queue.front();
        queue.pop();
        for (auto neighbour : adj[node]) {
          indegree[neighbour]--;

          if (indegree[neighbour] == 1) {
            queue.push(neighbour);
          }
        }
      }
    }

    vector<int> ans;
    while (!queue.empty()) {
      ans.push_back(queue.front());
      queue.pop();
    }

    return ans;
  }
};