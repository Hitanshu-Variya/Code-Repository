class Solution {
public:
  int findPages(vector<int> &arr, int k) {
    int size = arr.size();
    if (size < k) {
      return -1;
    }

    int low = *max_element(arr.begin(), arr.end()), high = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;

    function<bool(int)> possible = [&](int mid) -> bool {
      int count = 1;
      int sum = 0;

      for (int i = 0; i < size; i++) {
        sum += arr[i];
        if (sum > mid) {
          sum = arr[i];
          count++;
        }
      }

      return (count <= k);
    };

    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (possible(mid)) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return ans;
  }
};