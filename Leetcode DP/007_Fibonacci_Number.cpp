class Solution {
  public:
  int fib(int n) {
    int num1 = 0, num2 = 1;
    if (n == 0)
      return 0;
    if (n == 1)
      return 1;

    for (int i = 2; i <= n; i++) {
      int temp = num1;
      num1 = num2;
      num2 = (num2 + temp);
    }

    return num2;
  }
};