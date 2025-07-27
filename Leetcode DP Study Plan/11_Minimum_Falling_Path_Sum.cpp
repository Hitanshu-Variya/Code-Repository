class Solution {
  public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    int size = matrix.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++) {
      dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < size; i++) {
      for (int j = 0; j < size; j++) {
        int upLeft = (j - 1 >= 0) ? dp[i - 1][j - 1] : INT_MAX;
        int up = dp[i - 1][j];
        int upRight = (j + 1 < size) ? dp[i - 1][j + 1] : INT_MAX;

        dp[i][j] = matrix[i][j] + min({upLeft, up, upRight});
      }
    }

    int ans = *min_element(dp[size - 1].begin(), dp[size - 1].end());
    return ans;
  }
};