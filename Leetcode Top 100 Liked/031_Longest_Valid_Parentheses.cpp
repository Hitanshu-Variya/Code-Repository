class Solution {
  public:
  int longestValidParentheses(string s) {
    int size = s.size();
    vector<int> dp(size, 0);
    int ans = 0;

    for (int i = 1; i < size; i++) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          int prev = (i - 2 >= 0) ? dp[i - 2] : 0;
          dp[i] = prev + 2;
        } else if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
          int prev = (i - dp[i - 1] - 2 >= 0) ? dp[i - dp[i - 1] - 2] : 0;
          dp[i] = dp[i - 1] + 2 + prev;
        }

        ans = max(ans, dp[i]);
      }
    }

    return ans;
  }
};