class Solution {
  private:
  vector<int> topologicalSort(unordered_map<int, vector<int>> &graph, vector<int> &indegree) {
    int size = indegree.size();
    vector<int> ans;

    queue<int> queue;
    for (int i = 0; i < size; i++) {
      if (indegree[i] == 0)
        queue.push(i);
    }

    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();

      ans.push_back(node);
      for (int &neighbour : graph[node]) {
        indegree[neighbour]--;
        if (indegree[neighbour] == 0) {
          queue.push(neighbour);
        }
      }
    }

    return (ans.size() == graph.size()) ? ans : vector<int>();
  }

  public:
  vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
    int groupID = m;
    for (int i = 0; i < n; i++) {
      if (group[i] == -1) {
        group[i] = groupID++;
      }
    }

    unordered_map<int, vector<int>> itemGraph, groupGraph;
    vector<int> itemIndegree(n, 0), groupIndegree(groupID, 0);

    for (int i = 0; i < n; i++) {
      for (int item : beforeItems[i]) {
        itemGraph[item].push_back(i);
        itemIndegree[i]++;

        if (group[item] != group[i]) {
          groupGraph[group[item]].push_back(group[i]);
          groupIndegree[group[i]]++;
        }
      }
    }

    vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree);
    vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree);

    if (itemOrder.empty() || groupOrder.empty()) {
      return vector<int>();
    }

    unordered_map<int, vector<int>> orderedGroups;
    for (int item : itemOrder) {
      orderedGroups[group[item]].push_back(item);
    }

    vector<int> ans;
    for (int group : groupOrder) {
      ans.insert(ans.end(), orderedGroups[group].begin(), orderedGroups[group].end());
    }

    return ans;
  }
};