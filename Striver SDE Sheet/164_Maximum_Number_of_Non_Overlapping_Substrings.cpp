// Using Greedy
class Solution {
  public:
  vector<string> maxNumOfSubstrings(string s) {
    int size = s.size();
    vector<int> start(26, size), end(26, -1);
    for (int i = 0; i < size; i++) {
      start[s[i] - 'a'] = min(start[s[i] - 'a'], i);
      end[s[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
      int left = start[i], right = end[i];

      for (int j = left + 1; j < right; j++) {
        left = min(left, start[s[j] - 'a']);
        right = max(right, end[s[j] - 'a']);
      }

      start[i] = left;
      end[i] = right;
    }

    vector<vector<int>> interval;
    for (int i = 0; i < size; i++) {
      int left = start[s[i] - 'a'], right = end[s[i] - 'a'];
      if (left == i) {
        if (!interval.empty() && interval.back()[1] > right) {
          interval.pop_back();
        }
        interval.push_back({left, right});
      }
    }

    vector<string> ans;
    for (auto duration : interval) {
      int left = duration[0], right = duration[1];
      ans.push_back(s.substr(left, right - left + 1));
    }

    return ans;
  }
};

// Using Kosaraju Algorithm
class Solution {
  private:
  void DFS(int node, vector<vector<int>> &graph, vector<bool> &visited,
           stack<int> &end_time) {
    visited[node] = true;

    for (int neighbour : graph[node]) {
      if (!visited[neighbour]) {
        DFS(neighbour, graph, visited, end_time);
      }
    }

    end_time.push(node);
  }

  void DFS2(int node, vector<vector<int>> &rev_graph, vector<bool> &visited,
            vector<int> &components) {
    visited[node] = true;
    if (rev_graph[node].size() == 0)
      return;
    components.push_back(node);

    for (int neighbour : rev_graph[node]) {
      if (!visited[neighbour]) {
        DFS2(neighbour, rev_graph, visited, components);
      }
    }
  }

  void DFS3(int node, vector<vector<int>> &graph, vector<bool> &visited,
            map<int, int> &hash_map, bool &flag) {
    visited[node] = true;

    for (int neighbour : graph[node]) {
      if (hash_map[neighbour] != 1) {
        flag = false;
        return;
      }
      if (!visited[neighbour]) {
        DFS3(neighbour, graph, visited, hash_map, flag);
      }
    }
  }

  public:
  vector<string> maxNumOfSubstrings(string s) {
    int size = s.size();
    vector<int> start(26, INT_MAX), end(26, INT_MIN);
    for (int i = 0; i < size; i++) {
      start[s[i] - 'a'] = min(start[s[i] - 'a'], i);
      end[s[i] - 'a'] = i;
    }

    vector<vector<int>> graph(26);
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < 26; j++) {
        if (start[j] <= i && i <= end[j]) {
          graph[j].push_back(s[i] - 'a');
        }
      }
    }

    vector<vector<int>> rev_graph(26);
    for (int i = 0; i < 26; i++) {
      for (int neighbour : graph[i]) {
        rev_graph[neighbour].push_back(i);
      }
    }

    stack<int> end_time;
    vector<bool> visited(26, 0);
    for (int i = 0; i < 26; i++) {
      if (!visited[i]) {
        DFS(i, graph, visited, end_time);
      }
    }

    fill(visited.begin(), visited.end(), false);
    vector<vector<int>> SCC;
    for (int i = 0; i < 26; i++) {
      int node = end_time.top();
      end_time.pop();

      if (!visited[node]) {
        vector<int> components;
        DFS2(node, rev_graph, visited, components);
        SCC.push_back(components);
      }
    }

    fill(visited.begin(), visited.end(), false);
    vector<string> ans;
    for (auto itr : SCC) {
      if (itr.size() != 0) {
        map<int, int> hash_map;
        for (int node : itr)
          hash_map[node] = 1;

        bool flag = true;
        DFS3(itr[0], graph, visited, hash_map, flag);

        if (flag) {
          int min_left = INT_MAX, max_right = INT_MIN;
          for (int node : itr) {
            min_left = min(min_left, start[node]);
            max_right = max(max_right, end[node]);
          }

          ans.push_back(s.substr(min_left, max_right - min_left + 1));
        }
      }
    }

    return ans;
  }
};