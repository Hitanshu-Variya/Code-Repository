using i64 = long long int;
class Solution {
  private:
  double solver(double x, i64 n) {
    if (n < 0)
      return solver(1 / x, -n);
    if (n == 0)
      return 1.0;
    if (n == 1)
      return x;

    double term = solver(x, n / 2);
    double ans = term * term;

    if (n & 1)
      ans *= x;

    return ans;
  }

  public:
  double myPow(double x, int n) { 
    return solver(x, static_cast<i64>(n)); 
  }
};