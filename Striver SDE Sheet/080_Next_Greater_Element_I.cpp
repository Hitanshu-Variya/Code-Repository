class Solution {
  public:
  vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    int size1 = nums1.size(), size2 = nums2.size();
    unordered_map<int, int> nextGreater;
    stack<int> st;

    for (int i = size2 - 1; i >= 0; i--) {
      while (!st.empty() && nums2[i] > st.top()) {
        st.pop();
      }

      nextGreater[nums2[i]] = (st.empty()) ? -1 : st.top();
      st.push(nums2[i]);
    }

    vector<int> ans;
    for (int i = 0; i < size1; i++) {
      ans.push_back(nextGreater[nums1[i]]);
    }

    return ans;
  }
};