class Solution {
  public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int size = nums.size();
    vector<int> prefix(size, 1), suffix(size, 1);
    prefix[0] = nums[0];
    suffix[size - 1] = nums[size - 1];

    for (int i = 1; i < size; i++) {
      prefix[i] = prefix[i - 1] * nums[i];
    }

    for (int i = size - 2; i >= 0; i--) {
      suffix[i] = suffix[i + 1] * nums[i];
    }

    vector<int> ans(size, 1);
    ans[0] = suffix[1];
    ans[size - 1] = prefix[size - 2];

    for (int i = 1; i < size - 1; i++) {
      ans[i] = prefix[i - 1] * suffix[i + 1];
    }

    return ans;
  }
};