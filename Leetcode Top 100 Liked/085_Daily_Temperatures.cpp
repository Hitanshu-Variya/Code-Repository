class Solution {
  public:
  vector<int> dailyTemperatures(vector<int> &temperatures) {
    int size = temperatures.size();
    vector<int> ans(size);
    stack<int> st;

    for (int i = size - 1; i >= 0; i--) {
      while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
        st.pop();
      }

      ans[i] = (st.empty()) ? 0 : st.top() - i;
      st.push(i);
    }

    return ans;
  }
};