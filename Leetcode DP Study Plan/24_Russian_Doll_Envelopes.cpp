class Solution {
  public:
  int maxEnvelopes(vector<vector<int>> &envelopes) {
    int size = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), [&](const vector<int> &a, const vector<int> &b) -> bool {
      if (a[0] != b[0])
        return a[0] < b[0];
      return a[1] > b[1];
    });

    vector<int> LIS;
    for (int i = 0; i < size; i++) {
      int start = envelopes[i][0], end = envelopes[i][1];
      auto it = lower_bound(LIS.begin(), LIS.end(), end);

      if (it == LIS.end()) {
        LIS.push_back(end);
      } else {
        *it = end;
      }
    }

    return LIS.size();
  }
};