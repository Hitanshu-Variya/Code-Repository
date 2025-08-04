class Solution {
  public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    int size = nums.size();
    vector<int> ans;
    deque<int> deque;

    for (int i = 0; i < size; i++) {
      if (!deque.empty() && deque.front() == i - k)
        deque.pop_front();

      while (!deque.empty() && nums[deque.back()] <= nums[i])
        deque.pop_back();

      deque.push_back(i);
      if (i >= k - 1)
        ans.push_back(nums[deque.front()]);
    }

    return ans;
  }
};