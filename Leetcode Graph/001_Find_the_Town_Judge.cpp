class Solution {
  public:
  int findJudge(int n, vector<vector<int>> &trust) {
    vector<vector<int>> arr(n + 1, vector<int>(2, 0));
    for (auto itr : trust) {
      arr[itr[0]][0]++;
      arr[itr[1]][1]++;
    }

    for (int i = 1; i <= n; i++) {
      if (arr[i][1] == n - 1 && arr[i][0] == 0) {
        return i;
      }
    }

    return -1;
  }
};