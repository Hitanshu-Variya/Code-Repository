using i64 = long long int;
#define MOD (int)(1e9 + 7)

class Solution {
  public:
  int numTilings(int n) {
    if (n <= 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 5;

    vector<i64> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;

    for (int i = 4; i <= n; i++) {
      dp[i] = ((2 * dp[i - 1]) % MOD + dp[i - 3] % MOD) % MOD;
    }

    return static_cast<int>(dp[n]);
  }
};