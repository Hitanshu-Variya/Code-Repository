class Solution {
  private:
  vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  bool IS_SAFE(int &i, int &j, int &row, int &col, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
    return ((i < row) && (j < col) && (i >= 0) && (j >= 0) && (!visited[i][j]) && (grid[i][j] == '1'));
  }

  void DFS(int &i, int &j, int &row, int &col, vector<vector<bool>> &visited, vector<vector<char>> &grid) {
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
      int new_i = i + dir[k][0];
      int new_j = j + dir[k][1];

      if (IS_SAFE(new_i, new_j, row, col, visited, grid)) {
        DFS(new_i, new_j, row, col, visited, grid);
      }
    }
  }

  public:
  int numIslands(vector<vector<char>> &grid) {
    int row = grid.size();
    int col = grid[0].size();

    int islands = 0;
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (!visited[i][j] && grid[i][j] == '1') {
          DFS(i, j, row, col, visited, grid);
          islands++;
        }
      }
    }

    return islands;
  }
};