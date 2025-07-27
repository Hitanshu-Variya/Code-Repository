using uint = unsigned int;
class Solution {
  public:
  int combinationSum4(vector<int> &nums, int target) {
    int size = nums.size();
    vector<uint> dp(target + 1, 0);
    dp[0] = 1;

    for (int j = 1; j <= target; j++) {
      for (int num : nums) {
        if (j >= num) {
          dp[j] += dp[j - num];
        }
      }
    }

    return static_cast<int>(dp[target]);
  }
};