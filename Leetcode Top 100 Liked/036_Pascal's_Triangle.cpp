class Solution {
  public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans;
    for (int i = 0; i < numRows; i++) {
      vector<int> pascal(i + 1, 1);
      for (int j = 1; j <= (i / 2); j++) {
        pascal[j] = pascal[i - j] = pascal[j - 1] * (i - j + 1) / j;
      }

      ans.push_back(pascal);
    }

    return ans;
  }
};