class Solution {
  public:
  string addBinary(string a, string b) {
    string sum;
    int carry = 0;

    int size_a = a.size() - 1, size_b = b.size() - 1;
    while (size_a >= 0 || size_b >= 0 || carry) {
      if (size_a >= 0)
        carry += (a[size_a--] - '0');
      if (size_b >= 0)
        carry += (b[size_b--] - '0');

      sum += (carry % 2) + '0';
      carry /= 2;
    }

    reverse(sum.begin(), sum.end());
    return sum;
  }
};