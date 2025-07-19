class Solution {
  private:
  void computeLPSArray(string &pattern, int &p_size, vector<int> &LPS) {
    int len = 0;
    int j = 1;

    LPS[0] = 0;
    while (j < p_size) {
      if (pattern[j] == pattern[len]) {
        LPS[j] = len + 1;
        j++;
        len++;
      } else {
        if (len != 0) {
          len = LPS[len - 1];
        } else {
          LPS[j] = 0;
          j++;
        }
      }
    }
  }

  int KMP(string pattern, string text) {
    int p_size = pattern.size();
    int t_size = text.size();

    vector<int> LPS(p_size);
    computeLPSArray(pattern, p_size, LPS);

    int i = 0, j = 0;
    while (i < t_size) {
      if (text[i] == pattern[j]) {
        i++;
        j++;
      } else {
        if (j != 0) {
          j = LPS[j - 1];
        } else {
          i++;
        }
      }

      if (j == p_size) {
        return i - p_size;
      }
    }

    return -1;
  }

  public:
  int strStr(string haystack, string needle) { 
    return KMP(needle, haystack); 
  }
};