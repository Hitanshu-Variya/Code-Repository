class Solution {
  public:
  int singleNumber(vector<int> &nums) {
    int XOR = 0;
    for (auto num : nums)
      XOR = XOR ^ num;

    return XOR;
  }
};