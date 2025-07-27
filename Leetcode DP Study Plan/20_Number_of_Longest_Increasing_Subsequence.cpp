class Solution {
  public:
  int findNumberOfLIS(vector<int> &nums) {
    int size = nums.size();
    vector<int> dp(size, 1), freq(size, 1);

    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          if (1 + dp[j] > dp[i]) {
            dp[i] = 1 + dp[j];
            freq[i] = freq[j];
          } else if (1 + dp[j] == dp[i]) {
            freq[i] += freq[j];
          }
        }
      }
    }

    int maxLength = *max_element(dp.begin(), dp.end());
    int count = 0;
    for (int i = 0; i < size; i++) {
      if (dp[i] == maxLength) {
        count += freq[i];
      }
    }

    return count;
  }
};