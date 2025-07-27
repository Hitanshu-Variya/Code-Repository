class Solution {
  public:
  int longestArithSeqLength(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> dp(size, vector<int>(1001, 0));

    int ans = 1;
    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
        int difference = nums[i] - nums[j] + 500;
        dp[i][difference] = dp[j][difference] > 0 ? dp[j][difference] + 1 : 2;
        ans = max(ans, dp[i][difference]);
      }
    }

    return ans;
  }
};