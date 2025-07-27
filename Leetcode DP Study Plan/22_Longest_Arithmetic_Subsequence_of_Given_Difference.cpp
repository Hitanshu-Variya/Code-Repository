class Solution {
  public:
  int longestSubsequence(vector<int> &arr, int difference) {
    int size = arr.size();
    unordered_map<int, int> dp;

    int ans = 1;
    for (int i = 0; i < size; i++) {
      if (dp.find(arr[i] - difference) != dp.end()) {
        dp[arr[i]] = 1 + dp[arr[i] - difference];
      } else {
        dp[arr[i]] = 1;
      }

      ans = max(ans, dp[arr[i]]);
    }

    return ans;
  }
};