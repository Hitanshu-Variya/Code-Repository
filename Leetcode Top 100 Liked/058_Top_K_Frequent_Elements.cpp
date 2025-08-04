class Solution {
  public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    for (int &num : nums) {
      freq[num]++;
    }

    function<bool(pair<int, int> &, pair<int, int> &)> comparator = [&](pair<int, int> &a, pair<int, int> &b) -> bool {
      return a.first < b.first;
    };

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comparator)> pq(comparator);
    for (auto entry : freq) {
      pq.push({entry.second, entry.first});
    }

    vector<int> ans;
    while (k--) {
      ans.push_back(pq.top().second);
      pq.pop();
    }

    return ans;
  }
};