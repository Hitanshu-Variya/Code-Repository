using i64 = long long int;
class Solution {
  private:
  int countPairs(vector<int> &nums, int low, int mid, int high) {
    int count = 0, right = mid + 1;

    for (int i = low; i <= mid; i++) {
      while (right <= high && (i64)nums[i] > 2LL * (i64)nums[right])
        right++;
      count += (right - (mid + 1));
    }

    return count;
  }

  void merge(vector<int> &nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high) {
      if (nums[left] <= nums[right])
        temp.push_back(nums[left++]);
      else
        temp.push_back(nums[right++]);
    }

    while (left <= mid)
      temp.push_back(nums[left++]);
    while (right <= high)
      temp.push_back(nums[right++]);

    for (int i = low; i <= high; i++)
      nums[i] = temp[i - low];
  }

  int mergeSort(vector<int> &nums, int low, int high) {
    int count = 0;

    if (low < high) {
      int mid = low + (high - low) / 2;
      count += mergeSort(nums, low, mid);
      count += mergeSort(nums, mid + 1, high);
      count += countPairs(nums, low, mid, high);
      merge(nums, low, mid, high);
    }

    return count;
  }

  public:
  int reversePairs(vector<int> &nums) {
    return mergeSort(nums, 0, nums.size() - 1);
  }
};
