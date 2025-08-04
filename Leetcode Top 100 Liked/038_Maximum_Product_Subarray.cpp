class Solution {
  public:
  int maxProduct(vector<int> &nums) {
    int size = nums.size();
    double ans = INT_MIN;

    int left = 0, right = size - 1;
    double prefix_product = 1, suffix_product = 1;

    while (left < size && right >= 0) {
      prefix_product *= nums[left++];
      suffix_product *= nums[right--];

      ans = max({ans, prefix_product, suffix_product});

      if (prefix_product == 0)
        prefix_product = 1;
      if (suffix_product == 0)
        suffix_product = 1;
    }

    return static_cast<int>(ans);
  }
};