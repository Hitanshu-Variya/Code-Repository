class Solution {
  public:
  vector<int> maxOfMins(vector<int> &arr) {
    int size = arr.size();
    vector<int> prevSmallest(size), nextSmallest(size);
    stack<int> st;

    for (int i = 0; i < size; i++) {
      while (!st.empty() && arr[i] <= arr[st.top()]) {
        st.pop();
      }

      prevSmallest[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    st = stack<int>();
    for (int i = size - 1; i >= 0; i--) {
      while (!st.empty() && arr[i] <= arr[st.top()]) {
        st.pop();
      }

      nextSmallest[i] = st.empty() ? size : st.top();
      st.push(i);
    }

    vector<int> ans(size, 0);
    for (int i = 0; i < size; i++) {
      int length = nextSmallest[i] - prevSmallest[i] - 1;
      ans[length - 1] = max(ans[length - 1], arr[i]);
    }

    for (int i = size - 2; i >= 0; i--) {
      ans[i] = max(ans[i], ans[i + 1]);
    }

    return ans;
  }
};