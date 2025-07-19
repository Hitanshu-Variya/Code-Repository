class Solution {
  public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    int size = candidates.size();
    sort(candidates.begin(), candidates.end());

    vector<vector<int>> ans;
    vector<int> nums;

    function<void(int, int, vector<int> &)> solver =
        [&](int index, int sum, vector<int> &nums) -> void {
      if (sum == target) {
        ans.push_back(nums);
        return;
      }

      if (index == size || sum > target)
        return;

      nums.push_back(candidates[index]);
      solver(index + 1, sum + candidates[index], nums);
      nums.pop_back();

      while (index + 1 < size && candidates[index] == candidates[index + 1]) {
        index++;
      }

      solver(index + 1, sum, nums);
    };

    solver(0, 0, nums);
    return ans;
  }
};