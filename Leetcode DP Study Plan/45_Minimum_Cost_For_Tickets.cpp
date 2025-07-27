class Solution {
  public:
  int mincostTickets(vector<int> &days, vector<int> &costs) {
    unordered_set<int> travel(days.begin(), days.end());
    vector<int> dp(367, 0);

    for (int i = 365; i >= 1; --i) {
      if (!travel.count(i)) {
        dp[i] = dp[i + 1];
      } else {
        int take1 = costs[0] + dp[min(365, i + 1)];
        int take7 = costs[1] + dp[min(365, i + 7)];
        int take30 = costs[2] + dp[min(365, i + 30)];
        dp[i] = min({take1, take7, take30});
      }
    }

    return dp[days[0]];
  }
};