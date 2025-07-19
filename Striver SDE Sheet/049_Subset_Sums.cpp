class Solution {
  public:
  vector<int> subsetSums(vector<int> &arr) {
    int size = arr.size();
    vector<int> ans;

    function<void(int, int)> solver = [&](int index, int sum) -> void {
      if (index == size) {
        ans.push_back(sum);
        return;
      }

      solver(index + 1, sum);
      solver(index + 1, sum + arr[index]);
    };

    solver(0, 0);
    return ans;
  }
};