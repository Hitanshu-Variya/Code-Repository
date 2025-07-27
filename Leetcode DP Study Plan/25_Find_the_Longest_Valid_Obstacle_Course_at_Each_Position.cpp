class Solution {
  public:
  vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
    int size = obstacles.size();
    vector<int> LIS, ans;

    for (int i = 0; i < size; i++) {
      if (i == 0 || LIS.back() <= obstacles[i]) {
        LIS.push_back(obstacles[i]);
        ans.push_back(LIS.size());
      } else {
        int index = upper_bound(LIS.begin(), LIS.end(), obstacles[i]) - LIS.begin();
        LIS[index] = obstacles[i];
        ans.push_back(index + 1);
      }
    }

    return ans;
  }
};