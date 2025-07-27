class Solution {
  public:
  int maxProfit(vector<int> &prices, int fee) {
    int size = prices.size();
    vector<vector<int>> dp(size + 2, vector<int>(2, 0));

    for (int i = size - 1; i >= 0; i--) {
      for (int buy = 0; buy <= 1; buy++) {
        if (buy) {
          dp[i][buy] = max(dp[i + 1][buy], dp[i + 1][1 - buy] - prices[i]);
        } else {
          dp[i][buy] = max(dp[i + 1][buy], dp[i + 1][1 - buy] + prices[i] - fee);
        }
      }
    }

    return dp[0][1];
  }
};