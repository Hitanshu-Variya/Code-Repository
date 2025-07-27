class Solution {
  public:
  int deleteAndEarn(vector<int> &nums) {
    int size = nums.size();
    int maxNum = *max_element(nums.begin(), nums.end());
    vector<int> sum(maxNum + 1, 0), dp(maxNum + 1, 0);

    for (int &num : nums) {
      sum[num] += num;
    }

    dp[0] = 0;
    dp[1] = sum[1];

    for (int i = 2; i <= maxNum; i++) {
      dp[i] = max(dp[i - 2] + sum[i], dp[i - 1]);
    }

    return dp[maxNum];
  }
};