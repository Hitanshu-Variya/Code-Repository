class Solution {
  public:
  bool isSubsequence(string s, string t) {
    int s_size = s.size();
    int t_size = t.size();

    int s_ptr = 0, t_ptr = 0;
    while (s_ptr < s_size && t_ptr < t_size) {
      if (s[s_ptr] == t[t_ptr]) {
        s_ptr++;
      }

      t_ptr++;
    }

    return (s_ptr == s_size);
  }
};