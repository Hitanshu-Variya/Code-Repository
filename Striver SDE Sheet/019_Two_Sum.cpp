class Solution {
  public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int size = nums.size();
    unordered_map<int, int> hash_map;

    for (int i = 0; i < size; i++) {
      if (hash_map.find(target - nums[i]) != hash_map.end()) {
        return {hash_map[target - nums[i]], i};
      }

      hash_map[nums[i]] = i;
    }

    return {-1, -1};
  }
};