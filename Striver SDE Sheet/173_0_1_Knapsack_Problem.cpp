class Solution {
  public:
  int knapsack(int W, vector<int> &val, vector<int> &wt) {
    int size = val.size();
    vector<int> dp(W + 1, 0);

    for (int i = 1; i <= size; i++) {
      for (int j = W; j >= 0; j--) {
        if (wt[i - 1] <= j) {
          dp[j] = max(dp[j], dp[j - wt[i - 1]] + val[i - 1]);
        }
      }
    }

    return dp[W];
  }
};