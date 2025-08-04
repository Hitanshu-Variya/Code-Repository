class Solution {
  public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    function<bool(int &, int &)> isValid = [&](int &row, int &col) -> bool {
      for (int i = 0; i < n; i++) {
        if (i != row && board[i][col] == 'Q')
          return false;
        if (i != col && board[row][i] == 'Q')
          return false;
      }

      for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q')
          return false;
      }

      for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q')
          return false;
      }

      return true;
    };

    function<void(int)> getConfig = [&](int row) -> void {
      if (row == n) {
        ans.push_back(board);
        return;
      }

      for (int col = 0; col < n; col++) {
        if (isValid(row, col)) {
          board[row][col] = 'Q';
          getConfig(row + 1);
          board[row][col] = '.';
        }
      }
    };

    getConfig(0);
    return ans;
  }
};