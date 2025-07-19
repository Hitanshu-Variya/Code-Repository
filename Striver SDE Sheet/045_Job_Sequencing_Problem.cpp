class Solution {
  public:
  vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    int size = profit.size();
    vector<vector<int>> stats;

    for (int i = 0; i < size; i++) {
      stats.push_back({deadline[i], profit[i]});
    }

    sort(stats.begin(), stats.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < size; i++) {
      if (stats[i][0] > pq.size()) {
        pq.push(stats[i][1]);
      } else if (!pq.empty() && pq.top() < stats[i][1]) {
        pq.pop();
        pq.push(stats[i][1]);
      }
    }

    int sum = 0, count = 0;
    while (!pq.empty()) {
      sum += pq.top();
      pq.pop();
      count++;
    }

    return {count, sum};
  }
};