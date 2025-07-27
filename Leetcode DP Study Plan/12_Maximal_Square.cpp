class Solution {
  public:
  int maximalSquare(vector<vector<char>> &matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    int maxSize = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        dp[i][j] = (matrix[i][j] - '0');
        if (matrix[i][j] == '1')
          maxSize = 1;
      }
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (matrix[i][j] == '1') {
          if (dp[i - 1][j] && dp[i - 1][j - 1] && dp[i][j - 1]) {
            dp[i][j] += min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            maxSize = max(maxSize, dp[i][j]);
          }
        }
      }
    }

    return (maxSize * maxSize);
  }
};