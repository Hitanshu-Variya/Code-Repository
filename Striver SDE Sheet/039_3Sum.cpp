using i64 = long long int;
class Solution {
  public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    int size = nums.size();

    sort(nums.begin(), nums.end());

    for (int i = 0; i < size - 2; i++) {
      int j = i + 1;
      int k = size - 1;

      while (j < k) {
        i64 sum = (i64)nums[i] + (i64)nums[j] + (i64)nums[k];
        if (sum == 0) {
          ans.push_back({nums[i], nums[j], nums[k]});

          while (j < k && nums[++j] == nums[j - 1]);
          while (j < k && nums[--k] == nums[k + 1]);
        }

        if (sum > 0)
          k--;
        else if (sum < 0)
          j++;
      }

      while (i + 1 < size && nums[i] == nums[i + 1])
        i++;
    }

    return ans;
  }
};