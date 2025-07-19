class Solution {
  private:
  vector<int> parent, size;
  int find(int node) {
    if (parent[node] == node) {
      return node;
    }

    return (parent[node] = find(parent[node]));
  }

  void Union(int node1, int node2) {
    int parent1 = find(node1);
    int parent2 = find(node2);

    if (parent1 != parent2) {
      if (size[parent1] < size[parent2]) {
        swap(parent1, parent2);
      }

      parent[parent2] = parent1;
      size[parent1] += size[parent2];
    }
  }

  public:
  int kruskalsMST(int V, vector<vector<int>> &edges) {
    parent.resize(V);
    size.resize(V, 1);
    iota(parent.begin(), parent.end(), 0);

    sort(edges.begin(), edges.end(), [&](const vector<int> &a, const vector<int> &b) -> bool {
      return a[2] < b[2];
    });

    int sum = 0;
    for (auto &edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      if (find(u) == find(v))
        continue;

      sum += w;
      Union(u, v);
    }

    return sum;
  }
};