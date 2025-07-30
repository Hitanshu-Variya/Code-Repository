class Solution {
  private:
  void DFS(string source, string dest, map<string, list<pair<string, double>>> &adj, set<string> &visited, double temp_ans, double &ans) {
    visited.insert(source);
    if (source == dest) {
      ans = temp_ans;
      return;
    }

    for (auto itr : adj[source]) {
      string to_node = itr.first;
      double weight = itr.second;

      if (!visited.count(to_node)) {
        double new_temp = temp_ans * weight;
        DFS(to_node, dest, adj, visited, new_temp, ans);
      }
    }
  }

  public:
  vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
    int size = equations.size();
    map<string, list<pair<string, double>>> adj;
    set<string> all_nodes;
    vector<double> ans;

    for (int i = 0; i < size; i++) {
      string source = equations[i][0];
      string dest = equations[i][1];
      double weight = values[i];

      all_nodes.insert(source);
      all_nodes.insert(dest);

      adj[source].push_back({dest, weight});
      adj[dest].push_back({source, 1 / weight});
    }

    for (auto query : queries) {
      string source = query[0];
      string dest = query[1];

      if (!all_nodes.count(source) || !all_nodes.count(dest)) {
        ans.push_back((double)-1);
      } 
      else if (source == dest) {
        ans.push_back((double)1);
      } 
      else {
        set<string> visited;
        double ans_calculated = -1.0;
        DFS(source, dest, adj, visited, 1.0, ans_calculated);
        ans.push_back(ans_calculated);
      }
    }

    return ans;
  }
};