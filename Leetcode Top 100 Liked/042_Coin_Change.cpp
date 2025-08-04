using i64 = long long int;
class Solution {
  public:
  int coinChange(vector<int> &coins, int amount) {
    int n = coins.size();
    vector<i64> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
      for (int coin : coins) {
        if (coin <= i) {
          dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
      }
    }

    return dp[amount] == INT_MAX ? -1 : (int)dp[amount];
  }
};