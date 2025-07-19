class Solution {
  public:
  vector<int> topKSumPairs(vector<int> &a, vector<int> &b, int k) {
    int size_a = a.size(), size_b = b.size();
    vector<int> ans;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < size_a; i++) {
      pq.push({a[i] + b[size_b - 1], size_b - 1});
    }

    while (k--) {
      int num = pq.top().first;
      int index = pq.top().second;
      pq.pop();
      ans.push_back(num);

      if (index - 1 >= 0) {
        pq.push({num - b[index] + b[index - 1], index - 1});
      }
    }

    return ans;
  }
};