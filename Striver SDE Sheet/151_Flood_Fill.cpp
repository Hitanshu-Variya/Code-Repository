class Solution {
  private:
  vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  bool IS_SAFE(int &i, int &j, int &row, int &col, vector<vector<int>> &image, int &newColor, int &oldColor) {
    return ((i >= 0) && (j >= 0) && (i < row) && (j < col) && (image[i][j] == oldColor) && (image[i][j] != newColor));
  }

  void DFS(int i, int j, int &row, int &col, vector<vector<int>> &image, int &newColor, int &oldColor) {
    image[i][j] = newColor;

    for (int k = 0; k < 4; k++) {
      int new_row = i + dir[k][0];
      int new_col = j + dir[k][1];

      if (IS_SAFE(new_row, new_col, row, col, image, newColor, oldColor)) {
        DFS(new_row, new_col, row, col, image, newColor, oldColor);
      }
    }
  }

  public:
  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int row = image.size();
    int col = image[0].size();
    int oldColor = image[sr][sc];

    DFS(sr, sc, row, col, image, newColor, oldColor);
    return image;
  }
};