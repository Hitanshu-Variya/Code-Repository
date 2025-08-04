class Solution {
  public:
  bool canPartition(vector<int> &nums) {
    int size = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum & 1) {
      return false;
    }

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int i = 0; i < size; i++) {
      for (int j = target; j >= 1; j--) {
        if (j >= nums[i]) {
          dp[j] = dp[j] | dp[j - nums[i]];
        }
      }
    }

    return dp[target];
  }
};