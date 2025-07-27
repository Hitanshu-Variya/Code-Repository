using i64 = long long int;
class Solution {
  public:
  i64 mostPoints(vector<vector<int>> &questions) {
    int size = questions.size();
    vector<i64> dp(size + 1, 0);

    for (int i = size - 1; i >= 0; i--) {
      int index = i + questions[i][1] + 1;
      i64 notTake = dp[i + 1];
      i64 take = questions[i][0] + (index < size ? dp[index] : 0);

      dp[i] = max(take, notTake);
    }

    return dp[0];
  }
};