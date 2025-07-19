class Solution {
  public:
  vector<vector<int>> permute(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> ans;

    function<void(int)> solver = [&](int index) -> void {
      if (index == size) {
        ans.push_back(nums);
        return;
      }

      for (int i = index; i < size; i++) {
        swap(nums[index], nums[i]);
        solver(index + 1);
        swap(nums[index], nums[i]);
      }
    };

    solver(0);
    return ans;
  }
};