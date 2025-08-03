class Solution {
  public:
  int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
    int n = maze.size(), m = maze[0].size();

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<vector<int>> queue;

    queue.push({entrance[0], entrance[1], 0});
    visited[entrance[0]][entrance[1]] = true;

    function<bool(int, int)> isValid = [&](int x, int y) -> bool {
      return (x >= 0) && (x < n) && (y >= 0) && (y < m) && (!visited[x][y]) && (maze[x][y] == '.');
    };

    function<bool(int, int)> isExit = [&](int x, int y) -> bool {
      return ((x == 0) || (x == n - 1) || (y == 0) || (y == m - 1)) && !(x == entrance[0] && y == entrance[1]);
    };

    while (!queue.empty()) {
      int x = queue.front()[0];
      int y = queue.front()[1];
      int distance = queue.front()[2];
      queue.pop();

      if (isExit(x, y)) {
        return distance;
      }

      for (int i = 0; i < 4; i++) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (isValid(newX, newY)) {
          visited[newX][newY] = true;
          queue.push({newX, newY, distance + 1});
        }
      }
    }

    return -1;
  }
};