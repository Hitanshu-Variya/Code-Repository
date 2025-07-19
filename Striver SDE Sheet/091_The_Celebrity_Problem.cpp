class Solution {
  public:
  int celebrity(vector<vector<int>> &mat) {
    int size = mat.size();
    stack<int> st;

    for (int i = 0; i < size; i++) {
      st.push(i);
    }

    while (st.size() > 1) {
      int i = st.top();
      st.pop();
      int j = st.top();
      st.pop();

      if (mat[i][j] == 1) {
        st.push(j);
      } else {
        st.push(i);
      }
    }

    int candidate = st.top();
    for (int i = 0; i < size; i++) {
      if (i != candidate) {
        if (mat[candidate][i] == 1 || mat[i][candidate] == 0) {
          return -1;
        }
      }
    }

    return candidate;
  }
};