using i64 = long long int;
#define MOD (int)(1e9 + 7)

class Solution {
  public:
  int countGoodStrings(int low, int high, int zero, int one) {
    vector<i64> dp(high + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= high; i++) {
      i64 takeZeros = (i >= zero) ? dp[i - zero] : 0;
      i64 takeOnes = (i >= one) ? dp[i - one] : 0;

      dp[i] = (takeZeros % MOD + takeOnes % MOD) % MOD;
    }

    i64 ans = 0LL;
    for (int i = low; i <= high; i++) {
      ans = (ans % MOD + dp[i] % MOD) % MOD;
    }

    return ans;
  }
};