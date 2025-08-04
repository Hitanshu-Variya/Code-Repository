class Solution {
  public:
  void sortColors(vector<int> &nums) {
    int size = nums.size();
    int start = 0, mid = 0;
    int end = size - 1;

    while (mid <= end) {
      if (nums[mid] == 0) {
        swap(nums[start++], nums[mid++]);
      } else if (nums[mid] == 1) {
        mid++;
      } else {
        swap(nums[end--], nums[mid]);
      }
    }
  }
};