class Solution {
  public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int n = heights.size(), m = heights[0].size();

    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> pacific(n, vector<bool>(m, false));
    vector<vector<bool>> atlantic(n, vector<bool>(m, false));

    function<void(int, int, vector<vector<bool>> &)> DFS = [&](int x, int y, vector<vector<bool>> &visited) {
      visited[x][y] = true;

      for (int k = 0; k < 4; k++) {
        int newX = x + directions[k][0];
        int newY = y + directions[k][1];

        if ((newX >= 0) && (newX < n) && (newY >= 0) && (newY < m) && (!visited[newX][newY]) && (heights[newX][newY] >= heights[x][y])) {
          DFS(newX, newY, visited);
        }
      }
    };

    for (int i = 0; i < n; ++i) {
      DFS(i, 0, pacific);
      DFS(i, m - 1, atlantic);
    }

    for (int j = 0; j < m; ++j) {
      DFS(0, j, pacific);
      DFS(n - 1, j, atlantic);
    }

    vector<vector<int>> ans;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (pacific[i][j] && atlantic[i][j]) {
          ans.push_back({i, j});
        }
      }
    }

    return ans;
  }
};
