class Solution {
  public:
  int subarraySum(vector<int> &nums, int k) {
    int size = nums.size();
    unordered_map<int, int> hashMap;
    hashMap[0] = 1;

    int sum = 0, count = 0;
    for (int i = 0; i < size; i++) {
      sum += nums[i];
      count += hashMap[sum - k];
      hashMap[sum]++;
    }

    return count;
  }
};