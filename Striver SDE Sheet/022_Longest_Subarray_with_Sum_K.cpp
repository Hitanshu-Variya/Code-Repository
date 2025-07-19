class Solution {
  public:
  int longestSubarray(vector<int> &arr, int k) {
    int size = arr.size();
    unordered_map<int, int> hash_map;
    int sum = 0, ans = 0;

    for (int i = 0; i < size; i++) {
      sum += arr[i];

      if (sum == k) {
        ans = max(ans, i + 1);
      }

      if (hash_map.find(sum - k) != hash_map.end()) {
        ans = max(ans, i - hash_map[sum - k]);
      }

      if (hash_map.find(sum) == hash_map.end()) {
        hash_map[sum] = i;
      }
    }

    return ans;
  }
};