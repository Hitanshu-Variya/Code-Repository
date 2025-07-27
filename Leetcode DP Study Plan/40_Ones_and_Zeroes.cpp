class Solution {
  public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (string str : strs) {
      int total = str.size();
      int zeros = count(str.begin(), str.end(), '0');
      int ones = total - zeros;

      for (int i = m; i >= zeros; i--) {
        for (int j = n; j >= ones; j--) {
          dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
        }
      }
    }

    return dp[m][n];
  }
};