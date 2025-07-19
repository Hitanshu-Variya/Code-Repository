class Solution {
  public:
  int minDistance(string word1, string word2) {
    int size_1 = word1.size(), size_2 = word2.size();
    vector<vector<int>> dp(size_1 + 1, vector<int>(size_2 + 1, 0));

    for (int i = 1; i <= size_2; i++)
      dp[0][i] = i;
    for (int i = 1; i <= size_1; i++)
      dp[i][0] = i;

    for (int i = 1; i <= size_1; i++) {
      for (int j = 1; j <= size_2; j++) {
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
      }
    }

    return dp[size_1][size_2];
  }
};