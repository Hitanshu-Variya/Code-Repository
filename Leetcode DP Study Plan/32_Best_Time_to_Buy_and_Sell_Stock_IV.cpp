class Solution {
  public:
  int maxProfit(int k, vector<int> &prices) {
    int size = prices.size();
    vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int i = size - 1; i >= 0; i--) {
      for (int buy = 0; buy <= 1; buy++) {
        for (int limit = 1; limit <= k; limit++) {
          if (limit >= 1) {
            if (buy) {
              dp[i][buy][limit] = max(dp[i + 1][buy][limit], dp[i + 1][1 - buy][limit] - prices[i]);
            } else {
              dp[i][buy][limit] = max(dp[i + 1][buy][limit], dp[i + 1][1 - buy][limit - 1] + prices[i]);
            }
          }
        }
      }
    }

    return dp[0][1][k];
  }
};