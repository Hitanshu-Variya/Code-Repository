class Solution {
  public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    unordered_map<int, vector<int>> adj;
    vector<int> indegree(numCourses, 0);
    queue<int> queue;

    for (auto prerequisite : prerequisites) {
      adj[prerequisite[1]].push_back(prerequisite[0]);
      indegree[prerequisite[0]]++;
    }

    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] == 0)
        queue.push(i);
    }

    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();

      for (auto neighbour : adj[node]) {
        indegree[neighbour]--;
        if (indegree[neighbour] == 0) {
          queue.push(neighbour);
        }
      }
    }

    for (int i = 0; i < numCourses; i++) {
      if (indegree[i] != 0)
        return false;
    }

    return true;
  }
};