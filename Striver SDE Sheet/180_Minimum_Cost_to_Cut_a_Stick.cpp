class Solution {
  public:
  int minCost(int n, vector<int> &cuts) {
    int size = cuts.size();
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(size + 2, vector<int>(size + 2, 0));

    for (int i = size; i >= 1; i--) {
      for (int j = 1; j <= size; j++) {
        if (i > j) continue;
        dp[i][j] = INT_MAX;
        for (int k = i; k <= j; k++) {
          dp[i][j] = min(dp[i][j], cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j]);
        }
      }
    }

    return dp[1][size];
  }
};