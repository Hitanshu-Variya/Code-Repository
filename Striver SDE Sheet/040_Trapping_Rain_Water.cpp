class Solution {
  public:
  int trap(vector<int> &height) {
    int size = height.size();
    int left = 0, right = size - 1;
    int left_max = 0, right_max = 0;

    int ans = 0;
    while (left <= right) {
      left_max = max(left_max, height[left]);
      right_max = max(right_max, height[right]);

      ans += (left_max < right_max) ? left_max - height[left++] : right_max - height[right--];
    }

    return ans;
  }
};