class Solution {
  public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> ans;
    vector<int> indegree(numCourses, 0);
    unordered_map<int, vector<int>> adj;

    for (auto prerequisite : prerequisites) {
      adj[prerequisite[1]].push_back(prerequisite[0]);
      indegree[prerequisite[0]]++;
    }

    queue<int> queue;
    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0)
        queue.push(i);
    }

    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();

      ans.push_back(node);
      for (int neighbor : adj[node]) {
        indegree[neighbor]--;

        if (indegree[neighbor] == 0)
          queue.push(neighbor);
      }
    }

    for (auto itr : indegree) {
      if (itr != 0)
        return {};
    }

    return ans;
  }
};