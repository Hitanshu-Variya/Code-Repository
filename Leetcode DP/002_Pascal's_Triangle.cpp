class Solution {
  public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    vector<vector<int>> dp(numRows, vector<int>(numRows, 1));

    for (int i = 2; i < numRows; i++) {
      for (int j = 1; j < i; j++) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
    }

    for (int i = 0; i < numRows; i++) {
      vector<int> pascal;
      for (int j = 0; j <= i; j++) {
        pascal.push_back(dp[i][j]);
      }
      ans.push_back(pascal);
    }

    return ans;
  }
};