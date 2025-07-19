class Solution {
  private:
  void computeLPSArray(string &pattern, int &p_size, vector<int> &lps) {
    int len = 0;
    int j = 1;

    lps[0] = 0;
    while (j < p_size) {
      if (pattern[j] == pattern[len]) {
        lps[j] = len + 1;
        j++;
        len++;
      } else {
        if (len != 0) {
          len = lps[len - 1];
        } else {
          lps[j] = 0;
          j++;
        }
      }
    }
  }

  bool KMP(string pattern, string text) {
    int t_size = text.size();
    int p_size = pattern.size();

    vector<int> lps(p_size);
    computeLPSArray(pattern, p_size, lps);

    int i = 0, j = 0;
    while (i < t_size) {
      if (text[i] == pattern[j]) {
        i++;
        j++;
      } else {
        if (j != 0) {
          j = lps[j - 1];
        } else {
          i++;
        }
      }

      if (j == p_size) {
        return true;
      }
    }

    return false;
  }

  public:
  int repeatedStringMatch(string a, string b) {
    if (b == "")
      return 0;

    string new_a = a;
    int count = 1;

    while (new_a.size() < b.size()) {
      new_a += a;
      count++;
    }

    if (KMP(b, new_a))
      return count;

    new_a += a;
    if (KMP(b, new_a))
      return count + 1;

    return -1;
  }
};