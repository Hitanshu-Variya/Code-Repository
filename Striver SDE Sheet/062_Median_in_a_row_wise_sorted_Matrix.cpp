class Solution {
  public:
  int median(vector<vector<int>> &mat) {
    int n = mat.size(), m = mat[0].size();
    int required = (n * m) / 2;

    function<int(int)> getCount = [&](int num) -> int {
      int count = 0;
      for (auto &row : mat) {
        int low = 0, high = m - 1;
        while (low <= high) {
          int mid = low + (high - low) / 2;

          if (row[mid] <= num) {
            low = mid + 1;
          } else {
            high = mid - 1;
          }
        }

        count += low;
      }

      return count;
    };

    int low = 0, high = 2000;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int count = getCount(mid);

      if (count <= required) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }

    return low;
  }
};
