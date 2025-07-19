class Solution {
  public:
  int removeDuplicates(vector<int> &nums) {
    int size = nums.size();
    int start = 0, index = 1;

    while (index < size) {
      if (nums[index] > nums[start]) {
        start++;
        nums[start] = nums[index];
      }

      index++;
    }

    return start + 1;
  }
};