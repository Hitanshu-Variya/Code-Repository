class Solution {
  private:
  int LastElement(vector<int> &nums, int target) {
    int size = nums.size();
    int low = 0, high = size - 1;

    int ans = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] <= target) {
        ans = (nums[mid] == target) ? mid : ans;
        low = mid + 1;
      } else
        high = mid - 1;
    }

    return ans;
  }

  int FirstElement(vector<int> &nums, int target) {
    int size = nums.size();
    int low = 0, high = size - 1;

    int ans = -1;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (nums[mid] >= target) {
        ans = (nums[mid] == target) ? mid : ans;
        high = mid - 1;
      } else
        low = mid + 1;
    }

    return ans;
  }

  public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int first = FirstElement(nums, target);
    int last = LastElement(nums, target);

    return {first, last};
  }
};