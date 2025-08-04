class Solution {
  public:
  int maxSubArray(vector<int> &nums) {
    int size = nums.size();
    int sum = 0, ans = INT_MIN;
    for (int i = 0; i < size; i++) {
      sum += nums[i];
      ans = max(ans, sum);

      if (sum < 0)
        sum = 0;
    }

    return ans;
  }
};