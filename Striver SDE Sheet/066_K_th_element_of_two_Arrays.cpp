class Solution {
  public:
  int kthElement(vector<int> &a, vector<int> &b, int k) {
    int n = a.size(), m = b.size();
    if (n > m) {
      return kthElement(b, a, k);
    }

    int start = max(0, k - m), end = min(n, k);
    int left = k;

    while (start <= end) {
      int mid_1 = start + (end - start) / 2;
      int mid_2 = left - mid_1;

      int l1 = INT_MIN, l2 = INT_MIN;
      int r1 = INT_MAX, r2 = INT_MAX;

      if (mid_1 < n) r1 = a[mid_1];
      if (mid_2 < m) r2 = b[mid_2];
      if (mid_1 - 1 >= 0) l1 = a[mid_1 - 1];
      if (mid_2 - 1 >= 0) l2 = b[mid_2 - 1];

      if (l1 <= r2 && l2 <= r1) {
        return max(l1, l2);
      } else if (l1 > r2) {
        end = mid_1 - 1;
      } else
        start = mid_1 + 1;
    }

    return -1;
  }
};