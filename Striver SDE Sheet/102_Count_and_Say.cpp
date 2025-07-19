class Solution {
  private:
  string RLE(string s) {
    if (s == "")
      return "1";

    int size = s.size();
    string encoded = "";

    int count = 1;
    for (int i = 0; i < size - 1; i++) {
      if (s[i] == s[i + 1]) {
        count++;
      } else {
        encoded += (to_string(count) + s[i]);
        count = 1;
      }
    }

    encoded += (to_string(count) + s.back());
    return encoded;
  }

  public:
  string countAndSay(int n) {
    string ans = "";
    while (n--) {
      ans = RLE(ans);
    }

    return ans;
  }
};