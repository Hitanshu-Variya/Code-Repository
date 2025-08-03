class Solution {
  private:
  vector<int> parent, size;
  int find(int x) {
    if (parent[x] == x)
      return x;
    return (parent[x] = find(parent[x]));
  }

  void Union(int x, int y) {
    x = find(x);
    y = find(y);

    if (x != y) {
      if (size[x] > size[y]) {
        swap(x, y);
      }

      parent[x] = y;
      size[y] += size[x];
    }
  }

  public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    parent.resize(n * m);
    size.resize(n * m, 1);
    iota(parent.begin(), parent.end(), 0);

    function<bool(int, int)> isValid = [&](int x, int y) -> bool {
      return (x >= 0) && (x < n) && (y >= 0) && (y < m) && (grid[x][y] == 1);
    };

    bool hasOne = false;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          hasOne = true;
          int num1 = i * m + j;

          for (int k = 0; k < 4; k++) {
            int newI = i + directions[k][0];
            int newJ = j + directions[k][1];

            if (isValid(newI, newJ)) {
              int num2 = newI * m + newJ;
              Union(num1, num2);
            }
          }
        }
      }
    }

    if (!hasOne) {
      return 0;
    }

    int maxArea = *max_element(size.begin(), size.end());
    return maxArea;
  }
};