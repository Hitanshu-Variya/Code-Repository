using i64 = long long int;
class Solution {
  public:
  vector<int> getRow(int rowIndex) {
    vector<int> ans(rowIndex + 1, 1);
    for (int i = 1; i <= rowIndex / 2; i++) {
      ans[i] = ans[rowIndex - i] = (int)((i64)ans[i - 1] * (i64)(rowIndex - i + 1) / (i64)i);
    }

    return ans;
  }
};