class Solution {
  public:
  int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
      int u = manager[i], v = i;
      if (u == -1)
        continue;

      adj[u].push_back(v);
    }

    int totalTime = 0;
    queue<pair<int, int>> queue;
    queue.push({headID, 0});

    while (!queue.empty()) {
      auto [ID, time] = queue.front();
      queue.pop();

      totalTime = max(totalTime, time);

      for (int &neighbour : adj[ID]) {
        queue.push({neighbour, time + informTime[ID]});
      }
    }

    return totalTime;
  }
};