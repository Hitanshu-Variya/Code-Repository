class Solution {
  public:
  int numDecodings(string s) {
    if (s[0] == '0')
      return 0;

    int size = s.size();
    vector<int> dp(size + 1, 0);
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= size; i++) {
      if ('1' <= s[i - 1] && s[i - 1] <= '9')
        dp[i] += dp[i - 1];

      int num = stoi(s.substr(i - 2, 2));
      if (10 <= num && num <= 26)
        dp[i] += dp[i - 2];
    }

    return dp[size];
  }
};