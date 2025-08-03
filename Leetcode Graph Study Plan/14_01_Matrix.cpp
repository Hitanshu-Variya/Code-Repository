class Solution {
  public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int row = mat.size(), col = mat[0].size();
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    queue<pair<int, int>> queue;
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (mat[i][j] == 0)
          queue.push({i, j});
        else
          mat[i][j] = INT_MAX;
      }
    }

    while (!queue.empty()) {
      int x = queue.front().first;
      int y = queue.front().second;
      queue.pop();

      for (int k = 0; k < 4; k++) {
        int newX = x + dir[k][0];
        int newY = y + dir[k][1];

        if (newX >= 0 && newX < row && newY >= 0 && newY < col && mat[newX][newY] > mat[x][y] + 1) {
          mat[newX][newY] = mat[x][y] + 1;
          queue.push({newX, newY});
        }
      }
    }

    return mat;
  }
};