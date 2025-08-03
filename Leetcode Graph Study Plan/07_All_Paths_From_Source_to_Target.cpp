class Solution {
  public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    int size = graph.size();
    int source = 0, destination = size - 1;
    vector<vector<int>> paths;

    function<void(int, vector<int>)> DFS = [&](int node, vector<int> path) -> void {
      if (node == destination) {
        paths.push_back(path);
        return;
      }

      for (int &neighbour : graph[node]) {
        path.push_back(neighbour);
        DFS(neighbour, path);
        path.pop_back();
      }
    };

    DFS(0, {0});
    return paths;
  }
};