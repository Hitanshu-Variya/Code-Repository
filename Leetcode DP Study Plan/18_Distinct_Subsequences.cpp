using i64 = unsigned long long int;
class Solution {
  public:
  int numDistinct(string s, string t) {
    int s_size = s.size();
    int t_size = t.size();
    vector<vector<i64>> dp(s_size + 1, vector<i64>(t_size + 1, 0));

    // Base Cases
    // IF s == 0 -> dp[0][i] = 0 but dp[0][0] = 1;
    // IF t == 0 -> dp[i][0] = 1;
    for (int i = 0; i <= s_size; i++)
      dp[i][0] = 1;

    // Tabulation
    for (int i = 1; i <= s_size; i++) {
      for (int j = 1; j <= t_size; j++) {
        if (s[i - 1] == t[j - 1]) {
          i64 not_take = dp[i - 1][j];
          i64 take = dp[i - 1][j - 1];
          dp[i][j] = take + not_take;
        } else
          dp[i][j] = dp[i - 1][j];
      }
    }

    return static_cast<int>(dp[s_size][t_size]);
  }
};