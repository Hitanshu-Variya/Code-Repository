class Solution {
  public:
  int findKthLargest(vector<int> &nums, int k) {
    int minElement = *min_element(nums.begin(), nums.end());
    int maxElement = *max_element(nums.begin(), nums.end());

    int size = maxElement - minElement + 1;
    vector<int> freq(maxElement - minElement + 1, 0);
    for (int num : nums) {
      freq[num - minElement]++;
    }

    int threshold = k;
    for (int i = size - 1; i >= 0; i--) {
      threshold -= freq[i];
      if (threshold <= 0) {
        return i + minElement;
      }
    }

    return -1;
  }
};