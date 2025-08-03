class Solution {
  public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    int size = colors.size();
    vector<int> indegree(size, 0);
    vector<vector<int>> adj(size);

    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      indegree[edge[1]]++;
    }

    vector<vector<int>> dp(size, vector<int>(26, 0));
    queue<int> queue;

    for (int i = 0; i < size; i++) {
      if (indegree[i] == 0)
        queue.push(i);
      dp[i][colors[i] - 'a'] = 1;
    }

    int visited = 0, maxColor = 0;
    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();
      visited++;

      for (auto neighbour : adj[node]) {
        for (int i = 0; i < 26; i++) {
          int color = ((colors[neighbour] - 'a' == i) ? 1 : 0);
          dp[neighbour][i] = max(dp[neighbour][i], dp[node][i] + color);
        }

        indegree[neighbour]--;
        if (indegree[neighbour] == 0) {
          queue.push(neighbour);
        }
      }

      maxColor = max(maxColor, *max_element(dp[node].begin(), dp[node].end()));
    }

    return ((visited == size) ? maxColor : -1);
  }
};