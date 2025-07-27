class Solution {
  public:
  int minInsertions(string s) {
    string reverse_s = s;
    reverse(reverse_s.begin(), reverse_s.end());

    int size = s.size();
    vector<vector<int>> dp(size + 1, vector<int>(size + 1, 0));

    for (int i = 1; i <= size; i++) {
      for (int j = 1; j <= size; j++) {
        if (s[i - 1] == reverse_s[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }

    return (size - dp[size][size]);
  }
};