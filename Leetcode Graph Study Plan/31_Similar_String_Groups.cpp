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

  bool isSimilar(string &a, string &b) {
    int size = a.size(), diff = 0;
    for (int i = 0; i < size; i++) {
      if (a[i] != b[i]) {
        diff++;
        if (diff > 2)
          return false;
      }
    }

    return true;
  }

  public:
  int numSimilarGroups(vector<string> &strs) {
    int size = strs.size();
    parent.resize(size);
    iota(parent.begin(), parent.end(), 0);
    components = size;

    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if (isSimilar(strs[i], strs[j])) {
          Union(i, j);
        }
      }
    }

    return components;
  }
};