class Solution {
  public:
  int shortestPathAllKeys(vector<string> &grid) {
    int n = grid.size(), m = grid[0].size();

    pair<int, int> startPoint;
    vector<int> keys(26);
    int count = 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == '@') {
          startPoint = {i, j};
        }
        if (islower(grid[i][j])) {
          keys[grid[i][j] - 'a'] = count;
          count++;
        }
      }
    }

    vector<vector<vector<int>>> distance( n, vector<vector<int>>(m, vector<int>((1 << count), 1e5)));
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    queue<vector<int>> queue;
    queue.push({startPoint.first, startPoint.second, 0});
    distance[startPoint.first][startPoint.second][0] = 0;

    function<bool(int, int)> isValid = [&](int x, int y) -> bool {
      return (x >= 0) && (x < n) && (y >= 0) && (y < m) && (grid[x][y] != '#');
    };

    while (!queue.empty()) {
      int x = queue.front()[0];
      int y = queue.front()[1];
      int mask = queue.front()[2];
      queue.pop();

      if (mask == (1 << count) - 1) {
        return distance[x][y][mask];
      }

      for (int k = 0; k < 4; k++) {
        int newX = x + directions[k][0];
        int newY = y + directions[k][1];
        int newMask = mask;

        if (isValid(newX, newY)) {
          if (islower(grid[newX][newY])) {
            int index = keys[grid[newX][newY] - 'a'];
            newMask = newMask | (1 << index);
          }

          if (isupper(grid[newX][newY])) {
            int index = keys[grid[newX][newY] - 'A'];
            if (((newMask >> index) & 1) == 0)
              continue;
          }

          if (distance[newX][newY][newMask] > 1 + distance[x][y][mask]) {
            distance[newX][newY][newMask] = 1 + distance[x][y][mask];
            queue.push({newX, newY, newMask});
          }
        }
      }
    }

    return -1;
  }
};