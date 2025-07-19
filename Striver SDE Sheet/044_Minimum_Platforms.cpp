class Solution {
  public:
  int findPlatform(vector<int> &arr, vector<int> &dep) {
    int size = arr.size();
    vector<vector<int>> timings;

    for (int i = 0; i < size; i++) {
      timings.push_back({arr[i], dep[i]});
    }

    sort(timings.begin(), timings.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < size; i++) {
      if (!pq.empty() && pq.top() < timings[i][0]) {
        pq.pop();
      }

      pq.push(timings[i][1]);
    }

    return pq.size();
  }
};
