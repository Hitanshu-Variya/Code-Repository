class Solution {
  public:
  int longestCommonSubsequence(string text1, string text2) {
    int size_1 = text1.size(), size_2 = text2.size();
    vector<vector<int>> dp(size_1 + 1, vector<int>(size_2 + 1, 0));

    for (int i = 1; i <= size_1; i++) {
      for (int j = 1; j <= size_2; j++) {
        if (text1[i - 1] == text2[j - 1])
          dp[i][j] = dp[i - 1][j - 1] + 1;
        else
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }

    return dp[size_1][size_2];
  }
};