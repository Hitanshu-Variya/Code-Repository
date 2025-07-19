class Solution {
  public:
  bool wordBreak(string s, vector<string> &wordDict) {
    int size = s.size();
    unordered_set<string> hash_set(wordDict.begin(), wordDict.end());
    vector<bool> dp(size, false);
    dp[0] = true;

    for (int i = 1; i <= size; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && hash_set.find(s.substr(j, i - j)) != hash_set.end()) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[size];
  }
};