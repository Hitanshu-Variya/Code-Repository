class Solution {
  private:
  vector<int> parent;
  int components;

  int find(int node) {
    if (parent[node] == node)
      return node;
    return (parent[node] = find(parent[node]));
  }

  void Union(int node1, int node2) {
    node1 = find(node1);
    node2 = find(node2);

    if (node1 != node2) {
      parent[node1] = node2;
      components--;
    }
  }

  public:
  int isTree(int n, int m, vector<vector<int>> &adj) {
    components = n;
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);

    for (auto edge : adj) {
      int u = edge[0], v = edge[1];
      if (find(u) == find(v)) {
        return false;
      }

      Union(u, v);
    }

    if (components > 1) {
      return false;
    }

    return true;
  }
};
