class Solution {
  public:
  int majorityElement(vector<int> &nums) {
    int size = nums.size();
    int bucket = INT_MAX, count = 0;

    for (int num : nums) {
      if (num == bucket)
        count++;
      else if (count == 0) {
        bucket = num;
        count = 1;
      } else {
        count--;
      }
    }

    count = 0;
    for (int num : nums) {
      if (num == bucket)
        count++;
    }

    return (count > size / 2) ? bucket : -1;
  }
};