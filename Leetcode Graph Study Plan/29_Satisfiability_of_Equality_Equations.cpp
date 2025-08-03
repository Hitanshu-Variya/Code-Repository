class Solution {
  private:
  vector<int> parent;

  int find(int node) {
    if (parent[node] == node)
      return node;
    return (parent[node] = find(parent[node]));
  }

  void Union(int node1, int node2) {
    node1 = find(node1);
    node2 = find(node2);
    parent[node1] = node2;
  }

  public:
  bool equationsPossible(vector<string> &equations) {
    parent.resize(26);
    iota(parent.begin(), parent.end(), 0);

    for (string equation : equations) {
      char operation = equation[1];

      if (operation == '=') {
        int left = equation[0] - 'a', right = equation[3] - 'a';
        Union(left, right);
      }
    }

    for (string equation : equations) {
      int left = equation[0] - 'a', right = equation[3] - 'a';
      char operation = equation[1];

      if (operation == '!' && find(left) == find(right)) {
        return false;
      }
    }

    return true;
  }
};