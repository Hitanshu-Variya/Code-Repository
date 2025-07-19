class Solution {
  public:
  int largestRectangleArea(vector<int> &heights) {
    int size = heights.size();
    stack<int> st;
    vector<int> nextSmaller(size), prevSmaller(size);

    for (int i = size - 1; i >= 0; i--) {
      while (!st.empty() && heights[i] <= heights[st.top()]) {
        st.pop();
      }

      nextSmaller[i] = st.empty() ? size : st.top();
      st.push(i);
    }

    st = stack<int>();
    for (int i = 0; i < size; i++) {
      while (!st.empty() && heights[i] <= heights[st.top()]) {
        st.pop();
      }

      prevSmaller[i] = st.empty() ? -1 : st.top();
      st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < size; i++) {
      int nextElement = nextSmaller[i] - 1;
      int prevElement = prevSmaller[i] + 1;
      int width = (nextElement - prevElement + 1);

      ans = max(ans, heights[i] * width);
    }

    return ans;
  }
};