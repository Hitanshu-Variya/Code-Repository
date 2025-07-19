class Solution {
  public:
  int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit) {
    int size = startTime.size();
    vector<vector<int>> job;

    for (int i = 0; i < size; i++) {
      job.push_back({endTime[i], startTime[i], profit[i]});
    }

    sort(job.begin(), job.end());
    vector<int> dp(size + 1, 0);

    for (int i = 0; i < size; i++) {
      int index = upper_bound(job.begin(), job.begin() + i, job[i][1], [&](int start, vector<int> &job) -> bool {
        return start < job[0];
      }) - job.begin();

      dp[i + 1] = max(dp[i], job[i][2] + dp[index]);
    }

    return dp[size];
  }
};