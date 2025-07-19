class Solution {
  public:
  int matrixMultiplication(vector<int> &arr) {
    int size = arr.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));

    for (int length = 2; length < size; length++) {
      for (int i = 0; i < size - length; i++) {
        int j = i + length;
        dp[i][j] = INT_MAX;

        for (int k = i + 1; k < j; k++) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
        }
      }
    }

    return dp[0][size - 1];
  }
};