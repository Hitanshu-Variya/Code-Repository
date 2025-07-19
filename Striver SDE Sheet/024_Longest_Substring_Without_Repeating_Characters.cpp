class Solution {
  public:
  int lengthOfLongestSubstring(string s) {
    int size = s.size();
    int start = 0, end = 0;
    int ans = 0;

    unordered_map<char, bool> visited;
    while (end < size) {
      if (!visited[s[end]]) {
        visited[s[end]] = true;
      } else {
        while (visited[s[end]]) {
          visited[s[start++]] = false;
        }
        visited[s[end]] = true;
      }

      ans = max(ans, end - start + 1);
      end++;
    }

    return ans;
  }
};