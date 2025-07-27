// using 1D DP
using uint = unsigned int;
class Solution {
  public:
  int change(int amount, vector<int> &coins) {
    vector<uint> dp(amount + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
      for (int j = coin; j <= amount; j++) {
        dp[j] += dp[j - coin];
      }
    }

    return static_cast<int>(dp[amount]);
  }
};

// Using 2D DP
using uint = unsigned int;
class Solution {
  public:
  int change(int amount, vector<int> &coins) {
    int size = coins.size();
    vector<vector<uint>> dp(size + 1, vector<uint>(amount + 1, 0));

    // Base Cases
    // IF size == 0 -> dp[0][i] = 0;
    // IF amount == 0 -> dp[i][0] = 1;     // one combination (take nothing)
    for (int i = 0; i <= size; i++) {
      dp[i][0] = 1;
    }

    for (int i = 1; i <= size; i++) {
      for (int j = 1; j <= amount; j++) {
        dp[i][j] = dp[i - 1][j];
        if (j >= coins[i - 1]) {
          dp[i][j] += dp[i][j - coins[i - 1]];
        }
      }
    }

    return static_cast<int>(dp[size][amount]);
  }
};