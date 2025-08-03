class Solution {
  public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int size = graph.size();
    vector<int> outdegree(size, 0), ans;
    vector<vector<int>> parent(size);

    for (int i = 0; i < size; i++) {
      for (auto neighbour : graph[i]) {
        outdegree[i]++;
        parent[neighbour].push_back(i);
      }
    }

    queue<int> queue;
    for (int i = 0; i < size; i++) {
      if (!outdegree[i]) {
        queue.push(i);
        ans.push_back(i);
      }
    }

    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();

      for (auto parent : parent[node]) {
        outdegree[parent]--;
        if (outdegree[parent] == 0) {
          queue.push(parent);
          ans.push_back(parent);
        }
      }
    }

    sort(ans.begin(), ans.end());
    return ans;
  }
};