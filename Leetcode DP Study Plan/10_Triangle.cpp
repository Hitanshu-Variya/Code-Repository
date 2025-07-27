class Solution {
  public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int size = triangle.size();
    vector<int> dp(size);
    for (int i = 0; i < size; i++)
      dp[i] = triangle[size - 1][i];

    for (int i = size - 2; i >= 0; i--) {
      for (int j = 0; j <= i; j++) {
        dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
      }
    }

    return dp[0];
  }
};