class Solution {
  public:
  int minimumDeleteSum(string s1, string s2) {
    int size1 = s1.size(), size2 = s2.size();
    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    dp[0][0] = 0;

    for (int i = 1; i <= size1; i++) {
      dp[i][0] = dp[i - 1][0] + s1[i - 1];
    }

    for (int i = 1; i <= size2; i++) {
      dp[0][i] = dp[0][i - 1] + s2[i - 1];
    }

    for (int i = 1; i <= size1; i++) {
      for (int j = 1; j <= size2; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
        }
      }
    }

    return dp[size1][size2];
  }
};