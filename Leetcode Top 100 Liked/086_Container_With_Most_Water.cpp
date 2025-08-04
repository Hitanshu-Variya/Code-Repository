class Solution {
  public:
  int maxArea(vector<int> &height) {
    int size = height.size();
    int left = 0, right = size - 1;
    int max_area = 0;

    while (left < right) {
      int area = min(height[left], height[right]) * (right - left);
      max_area = max(area, max_area);

      ((height[left] > height[right]) ? right-- : left++);
    }

    return max_area;
  }
};