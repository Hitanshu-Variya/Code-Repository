class Solution {
  public:
  void setZeroes(vector<vector<int>> &matrix) {
    int row = matrix.size(), col = matrix[0].size();
    bool row_zero = false, col_zero = false;

    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (matrix[i][j] == 0) {
          if (i == 0)
            col_zero = true;
          if (j == 0)
            row_zero = true;

          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < col; i++) {
      if (matrix[0][i] == 0) {
        for (int j = 0; j < row; j++) {
          matrix[j][i] = 0;
        }
      }
    }

    for (int i = 1; i < row; i++) {
      if (matrix[i][0] == 0) {
        for (int j = 0; j < col; j++) {
          matrix[i][j] = 0;
        }
      }
    }

    if (col_zero) {
      for (int i = 0; i < col; i++) {
        matrix[0][i] = 0;
      }
    }

    if (row_zero) {
      for (int i = 0; i < row; i++) {
        matrix[i][0] = 0;
      }
    }
  }
};