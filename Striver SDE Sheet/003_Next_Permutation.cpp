class Solution {
  public:
  void nextPermutation(vector<int> &nums) {
    int size = nums.size();

    // step-1: Find break-point
    int index = -1;
    for (int i = size - 2; i >= 0; i--) {
      if (nums[i] < nums[i + 1]) {
        index = i;
        break;
      }
    }

    if (index == -1) {
      reverse(nums.begin(), nums.end());
      return;
    }

    // step-2: Find next greater element in right half
    for (int i = size - 1; i > index; i--) {
      if (nums[i] > nums[index]) {
        swap(nums[i], nums[index]);
        break;
      }
    }

    // step-3: Reverse right half
    reverse(nums.begin() + index + 1, nums.end());
  }
};