class Solution {
  public:
  vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    vector<int> ans;
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    for (int i = 0; i < K; i++) {
      pq.push({arr[i][0], i, 0});
    }

    while (!pq.empty()) {
      int num = pq.top()[0];
      int row = pq.top()[1];
      int col = pq.top()[2];
      pq.pop();

      ans.push_back(num);
      if (col + 1 < K) {
        pq.push({arr[row][col + 1], row, col + 1});
      }
    }

    return ans;
  }
};