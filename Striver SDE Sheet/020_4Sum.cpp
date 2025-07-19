using i64 = long long int;
class Solution {
  public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;

    for (int i = 0; i < size - 3; i++) {
      for (int j = i + 1; j < size - 2; j++) {
        int k = j + 1;
        int l = size - 1;

        while (k < l) {
          i64 sum = (i64)nums[i] + (i64)nums[j] + (i64)nums[k] + (i64)nums[l];
          if (sum == (i64)target) {
            ans.push_back({nums[i], nums[j], nums[k], nums[l]});
            while (k < l && nums[++k] == nums[k - 1]);
            while (k < l && nums[--l] == nums[l + 1]);
          }

          if (sum > target) {
            l--;
          } else if (sum < target) {
            k++;
          }
        }

        while (j + 1 < size && nums[j] == nums[j + 1])
          j++;
      }

      while (i + 1 < size && nums[i] == nums[i + 1])
        i++;
    }

    return ans;
  }
};