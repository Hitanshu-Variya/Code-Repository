class Solution {
  public:
  vector<vector<string>> partition(string s) {
    int size = s.size();
    vector<vector<bool>> dp(size, vector<bool>(size, false));

    for (int i = 0; i < size; i++) {
      dp[i][i] = true;
    }

    for (int length = 2; length <= size; length++) {
      for (int i = 0; i <= size - length; i++) {
        int j = i + length - 1;
        if (s[i] == s[j] && (length == 2 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
        }
      }
    }

    vector<vector<string>> ans;
    vector<string> path;

    function<void(int, vector<string> &)> solver = [&](int index, vector<string> &path) -> void {
      if (index == size) {
        ans.push_back(path);
        return;
      }

      for (int i = index; i < size; i++) {
        if (dp[index][i]) {
          path.push_back(s.substr(index, i - index + 1));
          solver(i + 1, path);
          path.pop_back();
        }
      }
    };

    solver(0, path);
    return ans;
  }
};