class Solution {
  public:
  vector<int> partitionLabels(string s) {
    int size = s.size();
    vector<int> ans;
    vector<int> lastSeen(26, -1);

    for (int i = size - 1; i >= 0; i--) {
      if (lastSeen[s[i] - 'a'] == -1) {
        lastSeen[s[i] - 'a'] = i;
      }
    }

    int start = 0, range = -1;
    for (int end = 0; end < size; end++) {
      range = max(range, lastSeen[s[end] - 'a']);
      
      if (end == range) {
        ans.push_back(end - start + 1);
        start = end + 1;
        range = -1;
      }
    }

    return ans;
  }
};