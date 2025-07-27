class Solution {
public:
  int tribonacci(int n) {
    int num_1 = 0, num_2 = 1, num_3 = 1;
    if (n == 0)
      return num_1;
    if (n == 1)
      return num_2;
    if (n == 2)
      return num_3;

    for (int i = 3; i <= n; i++) {
      int temp = num_1;
      num_1 = num_2;
      num_2 = num_3;
      num_3 = temp + num_1 + num_2;
    }

    return num_3;
  }
};