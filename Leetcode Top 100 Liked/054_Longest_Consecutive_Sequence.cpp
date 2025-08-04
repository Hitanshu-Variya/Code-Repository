class Solution {
  public:
  int longestConsecutive(vector<int> &nums) {
    int size = nums.size();
    int ans = 0;
    unordered_map<int, int> hash_map;

    for (int i = 0; i < size; i++) {
      hash_map[nums[i]] = 1;
    }

    for (int i = 0; i < size; i++) {
      if (hash_map.find(nums[i] - 1) != hash_map.end()) {
        hash_map[nums[i]] = 0;
      }
    }

    for (auto itr : hash_map) {
      if (itr.second) {
        int index = 0;
        while (hash_map.find(itr.first + index) != hash_map.end()) {
          index++;
        }
        ans = max(ans, index);
      }
    }

    return ans;
  }
};