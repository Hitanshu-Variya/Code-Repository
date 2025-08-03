class Solution {
  public:
  vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    vector<int> outDegree(n, 0);

    for (auto &edge : edges) {
      int u = edge[0], v = edge[1];
      adj[v].push_back(u);
      outDegree[u]++;
    }

    queue<int> queue;
    for (int i = 0; i < n; i++) {
      if (outDegree[i] == 0) {
        queue.push(i);
      }
    }

    vector<int> ans;
    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();

      bool isCandidate = true;
      for (int &neighbour : adj[node]) {
        isCandidate &= (outDegree[neighbour] <= 0);

        outDegree[neighbour]--;
        if (outDegree[neighbour] == 0) {
          queue.push(neighbour);
        }
      }

      if (isCandidate) {
        ans.push_back(node);
      }
    }

    return ans;
  }
};