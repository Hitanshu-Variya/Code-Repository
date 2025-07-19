class Solution {
  public:
  int maxSumIS(vector<int> &arr) {
    int size = arr.size();
    vector<int> dp(arr.begin(), arr.end());

    for (int i = 0; i < size; i++) {
      for (int j = 0; j < i; j++) {
        if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i]) {
          dp[i] = dp[j] + arr[i];
        }
      }
    }

    return *max_element(dp.begin(), dp.end());
  }
};