class MinStack {
  private:
  vector<vector<int>> st;

  public:
  MinStack() {}

  void push(int val) {
    int min_value = getMin();
    if (st.empty() || min_value > val) {
      min_value = val;
    }

    st.push_back({val, min_value});
  }

  void pop() { st.pop_back(); }

  int top() { return st.empty() ? -1 : st.back()[0]; }

  int getMin() { return st.empty() ? -1 : st.back()[1]; }
};