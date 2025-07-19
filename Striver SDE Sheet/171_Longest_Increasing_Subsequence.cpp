// Using Binary Search
class Solution {
  public:
  int lengthOfLIS(vector<int> &nums) {
    int size = nums.size();
    vector<int> LIS;
    LIS.push_back(nums[0]);

    for (int i = 1; i < size; i++) {
      if (LIS.back() < nums[i])
        LIS.push_back(nums[i]);
      else {
        int index = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
        LIS[index] = nums[i];
      }
    }

    return LIS.size();
  }
};

// Using DP
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