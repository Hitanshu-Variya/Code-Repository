// Using greedy
class Solution {
  public:
  int findLongestChain(vector<vector<int>> &pairs) {
    int size = pairs.size();
    sort(pairs.begin(), pairs.end(), [&](const vector<int> &a, const vector<int> &b) -> bool {
      return a[1] < b[1];
    });

    int end = INT_MIN, ans = 0;
    for (int i = 0; i < size; i++) {
      if (pairs[i][0] > end) {
        end = pairs[i][1];
        ans++;
      }
    }

    return ans;
  }
};

// Using DP
class Solution {
  public:
  int findLongestChain(vector<vector<int>> &pairs) {
    int size = pairs.size();
    sort(pairs.begin(), pairs.end());
    vector<int> dp(size, 1);

    for (int i = 1; i < size; i++) {
      for (int j = 0; j < i; j++) {
        if (pairs[i][0] > pairs[j][1] && dp[i] < 1 + dp[j]) {
          dp[i] = 1 + dp[j];
        }
      }
    }

    int ans = *max_element(dp.begin(), dp.end());
    return ans;
  }
};