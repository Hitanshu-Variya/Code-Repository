class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    int size = nums.size();
    if (size == 1) return nums[0];

    int low = 1, high = size - 2;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1]) {
        return nums[mid];
      }

      if (mid & 1) {
        if (nums[mid] == nums[mid - 1]) low = mid + 1;
        else high = mid - 1;
      } else {
        if (nums[mid] == nums[mid + 1]) low = mid + 1;
        else high = mid - 1;
      }
    }

    if (nums[0] != nums[1]) return nums[0];
    return nums[size - 1];
  }
};