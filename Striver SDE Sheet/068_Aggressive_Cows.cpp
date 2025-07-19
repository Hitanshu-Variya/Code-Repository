class Solution {
  public:
  int aggressiveCows(vector<int> &stalls, int k) {
    int size = stalls.size();
    sort(stalls.begin(), stalls.end());

    function<bool(int)> possible = [&](int mid) -> bool {
      int count = 1;
      int prev = 0;

      for (int i = 1; i < size; i++) {
        if (stalls[i] - stalls[prev] >= mid) {
          count++;
          prev = i;
        }
      }

      return (count >= k);
    };

    int low = 1, high = stalls[size - 1] - stalls[0];
    int ans = -1;

    while (low <= high) {
      int mid = low + (high - low) / 2;

      if (possible(mid)) {
        ans = mid;
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return ans;
  }
};