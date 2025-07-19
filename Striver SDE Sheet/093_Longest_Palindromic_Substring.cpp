class Solution {
  public:
  string longestPalindrome(string s) {
    int size = s.size();
    string ans{s[0]};
    int length = -1;

    for (int mid = 1; mid < size - 1; mid++) {
      for (int dx = 0; mid + dx < size && mid - dx >= 0; dx++) {
        if (s[mid + dx] != s[mid - dx]) {
          break;
        }

        if (2 * dx + 1 > length) {
          ans = s.substr(mid - dx, 2 * dx + 1);
          length = 2 * dx + 1;
        }
      }
    }

    for (int mid = 0; mid < size; mid++) {
      for (int dx = 0; mid + dx < size && mid - dx + 1 >= 0; dx++) {
        if (s[mid + dx] != s[mid - dx + 1]) {
          break;
        }

        if (2 * dx > length) {
          ans = s.substr(mid - dx + 1, 2 * dx);
          length = 2 * dx;
        }
      }
    }

    return ans;
  }
};