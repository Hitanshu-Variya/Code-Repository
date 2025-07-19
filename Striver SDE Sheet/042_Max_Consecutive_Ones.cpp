class Solution {
  public:
  int findMaxConsecutiveOnes(vector<int> &nums) {
    int size = nums.size();
    int ans = 0, sum = 0;

    for (int i = 0; i < size; i++) {
      if (nums[i] == 0)
        sum = 0;

      sum += nums[i];
      ans = max(ans, sum);
    }

    return ans;
  }
};