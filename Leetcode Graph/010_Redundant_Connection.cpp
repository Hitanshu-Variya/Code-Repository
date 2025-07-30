class Solution {
  private:
  vector<int> parent, size;
  int find(int i) {
    if (parent[i] == i)
      return i;
    return parent[i] = find(parent[i]);
  }

  void Union(int i, int j) {
    int vertex_i = find(i);
    int vertex_j = find(j);

    if (vertex_i != vertex_j) {
      if (size[vertex_i] < size[vertex_j]) {
        swap(i, j);
      }

      parent[vertex_j] = vertex_i;
      size[vertex_i] += size[vertex_j];
    }
  }

  public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    vector<int> ans;
    int n = edges.size();
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);

    for (auto edge : edges) {
      int u = edge[0], v = edge[1];
      if (find(u) == find(v)) {
        ans = {u, v};
        continue;
      }

      Union(u, v);
    }

    return ans;
  }
};