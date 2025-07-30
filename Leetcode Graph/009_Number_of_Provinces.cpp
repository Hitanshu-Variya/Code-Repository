class Solution {
  private:
  vector<int> parent, size;
  int find(int i) {
    if (parent[i] == i)
      return i;
    return (parent[i] = find(parent[i]));
  }

  void Union(int i, int j) {
    int parent_i = find(i);
    int parent_j = find(j);

    if (parent_i != parent_j) {
      if (size[parent_i] < size[parent_j]) {
        swap(parent_i, parent_j);
      }

      parent[parent_j] = parent_i;
      size[parent_i] += size[parent_j];
    }
  }

  public:
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    parent.resize(n);
    size.resize(n, 1);
    iota(parent.begin(), parent.end(), 0);

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (isConnected[i][j]) {
          Union(i, j);
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (parent[i] == i)
        ans++;
    }

    return ans;
  }
};