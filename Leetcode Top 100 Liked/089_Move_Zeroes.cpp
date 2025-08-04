class Solution {
  public:
  void moveZeroes(vector<int> &nums) {
    int size = nums.size();
    int i = 0;

    for (int j = 0; j < size; j++) {
      if (nums[j] != 0) {
        swap(nums[j], nums[i]);
        i++;
      }
    }
  }
};