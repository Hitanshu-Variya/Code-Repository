class Solution {
  public:
  string findOrder(vector<string> &words) {
    int size = words.size();
    vector<vector<int>> adj(26);
    vector<int> indegree(26, 0);
    vector<bool> present(26, false);

    for (const string &word : words) {
      for (char character : word) {
        present[character - 'a'] = true;
      }
    }

    for (int k = 0; k < size - 1; k++) {
      string s1 = words[k];
      string s2 = words[k + 1];

      int s1_size = s1.size(), s2_size = s2.size();
      int i = 0, j = 0;

      while (i < s1_size && j < s2_size) {
        if (s1[i] != s2[j]) {
          adj[s1[i] - 'a'].push_back(s2[j] - 'a');
          indegree[s2[j] - 'a']++;
          break;
        }

        i++;
        j++;
      }

      if (i == s2_size && s1_size > s2_size) {
        return "";
      }
    }

    queue<int> queue;
    for (int i = 0; i < 26; i++) {
      if (present[i] && indegree[i] == 0) {
        queue.push(i);
      }
    }

    string ans = "";
    while (!queue.empty()) {
      int node = queue.front();
      queue.pop();
      ans.push_back('a' + node);

      for (int &neighbour : adj[node]) {
        indegree[neighbour]--;
        if (indegree[neighbour] == 0) {
          queue.push(neighbour);
        }
      }
    }

    int total_present = count(present.begin(), present.end(), true);
    if (ans.size() != total_present)
      return "";

    return ans;
  }
};