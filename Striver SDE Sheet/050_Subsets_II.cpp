class Solution {
  public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    int size = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    function<void(int, vector<int>)> solver = [&](int index, vector<int> set) -> void {
      if (index == size) {
        ans.push_back(set);
        return;
      }

      set.push_back(nums[index]);
      solver(index + 1, set);
      set.pop_back();

      while (index + 1 < size && nums[index] == nums[index + 1]) {
        index++;
      }
      solver(index + 1, set);
    };

    solver(0, {});
    return ans;
  }
};