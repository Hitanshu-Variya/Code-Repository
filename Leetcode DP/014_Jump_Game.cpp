class Solution {
  public:
  bool canJump(vector<int> &nums) {
    int size = nums.size();
    int current_index = 0, next_index = 0;

    for (int i = 0; i < size; i++) {
      next_index = max(nums[i] + i, next_index);

      if (i == current_index) {
        current_index = next_index;
        next_index = 0;
      }

      if (current_index >= size - 1) {
        return true;
      }
    }

    return false;
  }
};