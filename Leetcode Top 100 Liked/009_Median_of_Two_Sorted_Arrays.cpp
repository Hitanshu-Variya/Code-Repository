class Solution {
  public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size();
    if (m > n) {
      return findMedianSortedArrays(nums2, nums1);
    }

    int low = 0, high = m;
    int left = (m + n + 1) / 2;

    while (low <= high) {
      int mid1 = low + (high - low) / 2;
      int mid2 = left - mid1;

      int l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
      if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
      if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];
      if (mid1 < m) r1 = nums1[mid1];
      if (mid2 < n) r2 = nums2[mid2];

      if (l1 <= r2 && l2 <= r1) {
        if ((m + n) % 2 == 0)
          return (double)((max(l1, l2) + min(r1, r2)) / 2.0);
        else
          return (double)(max(l1, l2));
      } else if (l1 > r2) {
        high = mid1 - 1;
      } else {
        low = mid1 + 1;
      }
    }

    return 0.0;
  }
};