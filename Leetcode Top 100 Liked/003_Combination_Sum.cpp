class Solution {
  public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    int size = candidates.size();
    vector<vector<int>> ans;
    vector<int> nums;

    function<void(int, int, vector<int> &)> solver = [&](int index, int sum, vector<int> &nums) -> void {
      if (sum == target) {
        ans.push_back(nums);
        return;
      }

      if (sum > target || index >= size)
        return;

      nums.push_back(candidates[index]);
      solver(index, sum + candidates[index], nums);
      nums.pop_back();

      solver(index + 1, sum, nums);
    };

    solver(0, 0, nums);
    return ans;
  }
};