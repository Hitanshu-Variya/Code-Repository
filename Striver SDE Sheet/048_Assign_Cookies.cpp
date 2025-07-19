class Solution {
  public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int content = 0;
    int g_index = g.size() - 1, s_index = s.size() - 1;
    while (g_index >= 0 && s_index >= 0) {
      if (g[g_index] <= s[s_index]) {
        content++;
        s_index--;
      }
      g_index--;
    }

    return content;
  }
};