class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int size = cost.size();
    vector<int> dp(size + 1, 0);
    dp[size - 1] = cost[size - 1];
    dp[size - 2] = cost[size - 2];

    for (int i = size - 3; i >= 0; i--) {
      dp[i] = cost[i] + min(dp[i + 1], dp[i + 2]);
    }

    return min(dp[0], dp[1]);
  }
};