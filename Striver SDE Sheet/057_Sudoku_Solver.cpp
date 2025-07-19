class Solution {
  private:
  bool solver(vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') {
          for (char k = '1'; k <= '9'; k++) {
            if (isValid(board, i, j, k)) {
              board[i][j] = k;
              if (solver(board)) {
                return true;
              }
              board[i][j] = '.';
            }
          }

          return false;
        }
      }
    }

    return true;
  }

  bool isValid(vector<vector<char>> &board, int &row, int &col, char &num) {
    for (int i = 0; i < 9; i++) {
      if (board[i][col] == num)
        return false;
      if (board[row][i] == num)
        return false;

      int boxRow = (row / 3) * 3 + (i / 3);
      int boxCol = (col / 3) * 3 + (i % 3);
      if (board[boxRow][boxCol] == num)
        return false;
    }

    return true;
  }

  public:
  void solveSudoku(vector<vector<char>> &board) { 
    solver(board); 
  }
};