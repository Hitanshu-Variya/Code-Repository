class Solution {
  public:
  double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity) {
    int size = val.size();
    vector<tuple<double, int, int>> stats;

    for (int i = 0; i < size; i++) {
      stats.push_back(make_tuple((double)(val[i] * 1.0) / wt[i], val[i], wt[i]));
    }

    sort(stats.begin(), stats.end(), greater<>());
    double ans = 0.0;

    for (int i = 0; i < size; i++) {
      double perValue = get<0>(stats[i]);
      int value = get<1>(stats[i]);
      int weight = get<2>(stats[i]);

      if (capacity >= weight) {
        capacity -= weight;
        ans += (double)value;
      } else {
        ans += perValue * capacity;
        return ans;
      }
    }

    return ans;
  }
};
