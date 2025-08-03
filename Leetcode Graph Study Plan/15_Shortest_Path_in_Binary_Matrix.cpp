class Solution {
  public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    if (grid[0][0] == 1) {
      return -1;
    }

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0},  {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    int distance = 1;

    queue<pair<int, int>> queue;
    queue.push({0, 0});
    visited[0][0] = true;

    function<bool(int, int)> isValid = [&](int x, int y) -> bool {
      return (x >= 0) && (x < n) && (y >= 0) && (y < n) && (!visited[x][y]) && (grid[x][y] == 0);
    };

    while (!queue.empty()) {
      int size = queue.size();

      for (int i = 0; i < size; i++) {
        auto [x, y] = queue.front();
        queue.pop();

        if (x == n - 1 && y == n - 1) {
          return distance;
        }

        for (int k = 0; k < 8; k++) {
          int newX = x + directions[k][0];
          int newY = y + directions[k][1];

          if (isValid(newX, newY)) {
            visited[newX][newY] = true;
            queue.push({newX, newY});
          }
        }
      }

      distance++;
    }

    return -1;
  }
};