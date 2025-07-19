class Solution {
  public:
  vector<int> countDistinct(vector<int> &arr, int k) {
    int size = arr.size();
    vector<int> ans;
    k--;

    unordered_map<int, int> freq;
    int distinct = 0;
    int start = 0, end = 0;

    for (end = 0; end < size; end++) {
      int num = arr[end];

      if (freq[num] == 0) distinct++;
      freq[num]++;

      if (end == k) {
        ans.push_back(distinct);
      } else if (end > k) {
        freq[arr[start]]--;
        if (freq[arr[start]] == 0) distinct--;
        start++;

        ans.push_back(distinct);
      }
    }

    return ans;
  }
};