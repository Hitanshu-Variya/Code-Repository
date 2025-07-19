class Solution {
  public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    ans.push_back({1});

    for (int i = 1; i < numRows; i++) {
      vector<int> sequence = {1};
      for (int j = 1; j <= i; j++) {
        int sum = 0;
        if (j >= 0 && j < i)
          sum += ans[i - 1][j];
        if (j - 1 >= 0)
          sum += ans[i - 1][j - 1];
        sequence.push_back(sum);
      }
      ans.push_back(sequence);
    }

    return ans;
  }
};