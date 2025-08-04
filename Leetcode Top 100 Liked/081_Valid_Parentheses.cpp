class Solution {
  public:
  bool isValid(string s) {
    int size = s.size();
    stack<int> st;
    unordered_map<char, char> hash_map = {{')', '('}, {']', '['}, {'}', '{'}};

    for (int i = 0; i < size; i++) {
      if (hash_map.find(s[i]) == hash_map.end()) {
        st.push(s[i]);
      } else if (!st.empty() && hash_map[s[i]] == st.top()) {
        st.pop();
      } else {
        return false;
      }
    }

    return st.empty();
  }
};