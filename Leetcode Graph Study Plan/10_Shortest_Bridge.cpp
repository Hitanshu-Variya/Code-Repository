class Solution {
  public:
  int shortestBridge(vector<vector<int>> &grid) {
    int size = grid.size();

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited(size, vector<bool>(size, false));
    queue<vector<int>> queue;

    function<bool(int, int)> isValid = [&](int x, int y) -> bool {
      return (x >= 0) && (x < size) && (y >= 0) && (y < size);
    };

    function<void(int, int)> DFS = [&](int x, int y) -> void {
      visited[x][y] = true;
      queue.push({x, y, 0});

      for (int k = 0; k < 4; k++) {
        int newX = x + directions[k][0];
        int newY = y + directions[k][1];

        if (isValid(newX, newY) && (!visited[newX][newY]) && (grid[newX][newY] == 1)) {
          DFS(newX, newY);
        }
      }
    };

    bool found = false;
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (grid[i][j]) {
          DFS(i, j);
          found = true;
          break;
        }
      }

      if (found) {
        break;
      }
    }

    while (!queue.empty()) {
      int x = queue.front()[0];
      int y = queue.front()[1];
      int distance = queue.front()[2];
      queue.pop();

      for (int k = 0; k < 4; k++) {
        int newX = x + directions[k][0];
        int newY = y + directions[k][1];

        if (isValid(newX, newY) && !visited[newX][newY]) {
          if (grid[newX][newY] == 1) {
            return distance;
          }

          visited[newX][newY] = true;
          queue.push({newX, newY, distance + 1});
        }
      }
    }

    return -1;
  }
};