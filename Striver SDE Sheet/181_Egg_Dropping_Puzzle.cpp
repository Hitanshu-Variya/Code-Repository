class Solution {
  public:
  int eggDrop(int n, int k) {
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
      dp[i][1] = 1;
    }

    for (int i = 1; i <= k; i++) {
      dp[1][i] = i;
    }

    for (int i = 2; i <= n; i++) {
      for (int j = 2; j <= k; j++) {
        int min_turns = INT_MAX;
        int low = 1, high = j;

        while (low <= high) {
          int mid = low + (high - low) / 2;

          int breaks = dp[i - 1][mid - 1];
          int notBreaks = dp[i][j - mid];
          int turns = 1 + max(breaks, notBreaks);
          min_turns = min(min_turns, turns);

          if (breaks < notBreaks) {
            low = mid + 1;
          } else {
            high = mid - 1;
          }
        }

        dp[i][j] = min_turns;
      }
    }

    return dp[n][k];
  }
};