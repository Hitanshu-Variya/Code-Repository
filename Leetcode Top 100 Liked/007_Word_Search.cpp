class Solution {
  public:
  bool exist(vector<vector<char>> &board, string word) {
    int n = board.size(), m = board[0].size();
    int size = word.size();

    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    function<bool(int, int, int)> isValid = [&](int x, int y, int index) -> bool {
      return (x >= 0) && (x < n) && (y >= 0) && (y < m) && (!visited[x][y]) && (board[x][y] == word[index]);
    };

    function<bool(int, int, int)> DFS = [&](int x, int y, int index) -> bool {
      if (index + 1 == size) {
        return true;
      }

      visited[x][y] = true;

      for (int k = 0; k < 4; k++) {
        int newX = x + directions[k][0];
        int newY = y + directions[k][1];

        if (isValid(newX, newY, index + 1) && DFS(newX, newY, index + 1)) {
          visited[x][y] = false;
          return true;
        }
      }

      visited[x][y] = false;
      return false;
    };

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (board[i][j] == word[0] && DFS(i, j, 0)) {
          return true;
        }
      }
    }

    return false;
  }
};