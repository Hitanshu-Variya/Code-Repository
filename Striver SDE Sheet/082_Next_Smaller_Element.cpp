vector<int> nextSmallerElement(vector<int> &arr, int n) {
  vector<int> ans(n, -1);
  stack<int> st;

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && arr[i] <= st.top()) {
      st.pop();
    }

    ans[i] = (st.empty()) ? -1 : st.top();
    st.push(arr[i]);
  }

  return ans;
}