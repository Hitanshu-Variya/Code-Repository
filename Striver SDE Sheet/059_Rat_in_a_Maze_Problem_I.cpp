class Solution {
  public:
  vector<string> ratInMaze(vector<vector<int>> &maze) {
    int size = maze.size();
    vector<string> ans;

    vector<vector<bool>> visited(size, vector<bool>(size, false));
    vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    string move = "RLDU";

    function<bool(int, int)> isValid = [&](int row, int col) -> bool {
      return (row >= 0) && (row < size) && (col >= 0) && (col < size) && (!visited[row][col]) && (maze[row][col] != 0);
    };

    function<void(int, int, string)> DFS = [&](int row, int col, string path) -> void {
      visited[row][col] = true;

      if (row == size - 1 && col == size - 1) {
        ans.push_back(path);
        visited[row][col] = false;
        return;
      }

      for (int i = 0; i < 4; i++) {
        int new_row = row + directions[i][0];
        int new_col = col + directions[i][1];

        if (isValid(new_row, new_col)) {
          path.push_back(move[i]);
          DFS(new_row, new_col, path);
          path.pop_back();
        }
      }

      visited[row][col] = false;
    };

    DFS(0, 0, "");

    sort(ans.begin(), ans.end());
    return ans;
  }
};