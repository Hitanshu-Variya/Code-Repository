class Solution {
  public:
  string minWindow(string s, string t) {
    int s_size = s.size();
    int t_size = t.size();
    if (t_size > s_size) {
      return "";
    }

    unordered_map<char, int> hash_map;
    for (auto character : t) {
      hash_map[character]++;
    }

    int start = 0, end = 0;
    int count = t_size;
    int head = 0, min_length = INT_MAX;

    while (end < s_size) {
      if (hash_map[s[end]]-- > 0) {
        count--;
      }

      while (count == 0) {
        if (end - start + 1 < min_length) {
          head = start;
          min_length = end - start + 1;
        }

        if (hash_map[s[start++]]++ == 0) {
          count++;
        }
      }

      end++;
    }

    return (min_length == INT_MAX) ? "" : s.substr(head, min_length);
  }
};