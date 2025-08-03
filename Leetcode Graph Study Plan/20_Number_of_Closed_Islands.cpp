class Solution {
  public:
  int closedIsland(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> queue;

    for (int i = 0; i < n; i++) {
      if (grid[i][0] == 0) {
        queue.push({i, 0});
        visited[i][0] = true;
      }

      if (grid[i][m - 1] == 0) {
        queue.push({i, m - 1});
        visited[i][m - 1] = true;
      }
    }

    for (int j = 0; j < m; j++) {
      if (grid[0][j] == 0) {
        queue.push({0, j});
        visited[0][j] = true;
      }

      if (grid[n - 1][j] == 0) {
        queue.push({n - 1, j});
        visited[n - 1][j] = true;
      }
    }

    function<bool(int, int)> isValid = [&](int x, int y) -> bool {
      return (x >= 0) && (x < n) && (y >= 0) && (y < m) && (!visited[x][y]) && (grid[x][y] == 0);
    };

    while (!queue.empty()) {
      auto [x, y] = queue.front();
      queue.pop();

      for (int k = 0; k < 4; k++) {
        int newX = x + directions[k][0];
        int newY = y + directions[k][1];

        if (isValid(newX, newY)) {
          visited[newX][newY] = true;
          queue.push({newX, newY});
        }
      }
    }

    function<void(int, int)> DFS = [&](int x, int y) -> void {
      visited[x][y] = true;

      for (int k = 0; k < 4; k++) {
        int newX = x + directions[k][0];
        int newY = y + directions[k][1];

        if (isValid(newX, newY)) {
          DFS(newX, newY);
        }
      }
    };

    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 0 && !visited[i][j]) {
          DFS(i, j);
          count++;
        }
      }
    }

    return count;
  }
};