class Solution {
  public:
  vector<vector<int>> subsets(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> ans;

    function<void(int, vector<int>)> solver = [&](int index, vector<int> subset) -> void {
      if (index == size) {
        ans.push_back(subset);
        return;
      }

      subset.push_back(nums[index]);
      solver(index + 1, subset);
      subset.pop_back();

      solver(index + 1, subset);
    };

    solver(0, vector<int>());
    return ans;
  }
};