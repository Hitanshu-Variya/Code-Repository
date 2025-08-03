class Solution {
  public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<vector<int>> adj(n);
    for (auto road : roads) {
      int u = road[0], v = road[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int roadI = adj[i].size();
        int roadJ = adj[j].size();
        int common = (find(adj[i].begin(), adj[i].end(), j) != adj[i].end()) ? 1 : 0;

        ans = max(ans, roadI + roadJ - common);
      }
    }

    return ans;
  }
};