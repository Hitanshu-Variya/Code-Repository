class Solution {
  public:
  vector<int> findAnagrams(string s, string p) {
    int s_size = s.size(), p_size = p.size();
    if (s_size < p_size) {
      return vector<int>();
    }

    vector<int> P(26, 0), S(26, 0);
    for (char &character : p) {
      P[character - 'a']++;
    }

    vector<int> ans;
    for (int i = 0; i < s_size; i++) {
      S[s[i] - 'a']++;

      if (i >= p_size) {
        S[s[i - p_size] - 'a']--;
      }

      if (P == S) {
        ans.push_back(i - p_size + 1);
      }
    }

    return ans;
  }
};
