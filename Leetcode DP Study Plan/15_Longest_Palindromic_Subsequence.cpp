class Solution {
  public:
  int longestPalindromeSubseq(string s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());

    int size = s.size();
    vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));

    for (int i = 1; i <= size; i++) {
      for (int j = 1; j <= size; j++) {
        if (s[i - 1] == reversed[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return dp[size][size];
  }
};