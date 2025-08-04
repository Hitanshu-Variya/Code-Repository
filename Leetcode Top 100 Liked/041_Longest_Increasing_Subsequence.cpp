class Solution {
  public:
  int lengthOfLIS(vector<int> &nums) {
    int size = nums.size();
    vector<int> dp(size, 1);

    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
          dp[i] = dp[j] + 1;
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};