class Solution {
  public:
  int jump(vector<int> &nums) {
    int size = nums.size();
    int current_range = 0, next_range = 0;
    int count = 0;

    for (int i = 0; i < size; i++) {
      next_range = max(nums[i] + i, next_range);

      if (current_range >= size - 1) {
        break;
      }

      if (i == current_range) {
        current_range = next_range;
        next_range = 0;
        count++;
      }
    }

    return count;
  }
};