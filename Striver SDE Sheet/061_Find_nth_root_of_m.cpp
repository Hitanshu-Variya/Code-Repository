using i64 = long long int;
class Solution {
  private:
  i64 power(i64 a, i64 b) {
    if (b == 0)
      return 1;
    if (b == 1)
      return a;

    i64 num = power(a, b / 2);
    i64 ans = num * num;

    if (b & 1)
      ans *= a;

    return ans;
  }

  public:
  int nthRoot(int n, int m) {
    i64 low = 1, high = m;

    while (low <= high) {
      i64 mid = low + (high - low) / 2;
      i64 num = power(mid, n);
      if (num == m) {
        return mid;
      } else if (num < m) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return -1;
  }
};