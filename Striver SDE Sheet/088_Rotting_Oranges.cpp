class Solution {
  private:
  vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
  int orangesRotting(vector<vector<int>> &grid) {
    int row = grid.size();
    int col = grid[0].size();

    int minutes = 0;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    queue<vector<int>> queue;

    function<bool(int, int)> IS_VALID = [&](int i, int j) {
      return ((i >= 0) && (i < row) && (j >= 0) && (j < col) && (!visited[i][j]) && (grid[i][j] == 1));
    };

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 2)
          queue.push({i, j, 0});
      }
    }

    while (!queue.empty()) {
      vector<int> front = queue.front();
      int i = front[0], j = front[1], time = front[2];
      queue.pop();

      visited[i][j] = true;
      grid[i][j] = 2;

      for (int k = 0; k < 4; k++) {
        int new_i = i + dir[k][0];
        int new_j = j + dir[k][1];

        if (IS_VALID(new_i, new_j)) {
          visited[new_i][new_j] = true;
          grid[new_i][new_j] = 2;
          minutes = max(minutes, time + 1);
          queue.push({new_i, new_j, time + 1});
        }
      }
    }

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 1)
          return -1;
      }
    }

    return minutes;
  }
};