class Solution {
  public:
  string longestCommonPrefix(vector<string> &strs) {
    int size = 1e5;
    for (string str : strs) {
      size = min(size, (int)str.size());
    }

    string ans = "";
    for (int i = 0; i < size; i++) {
      char s = strs[0][i];
      for (auto str : strs) {
        if (str[i] != s)
          return ans;
      }

      ans += s;
    }

    return ans;
  }
};