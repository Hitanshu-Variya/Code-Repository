class Solution {
  private:
  void computeLPSArray(string &s, int &size, vector<int> &LPS) {
    int len = 0;
    int j = 1;

    LPS[0] = 0;
    while (j < size) {
      if (s[j] == s[len]) {
        LPS[j] = len + 1;
        j++;
        len++;
      } 
      else {
        if (len != 0) {
          len = LPS[len - 1];
        } 
        else {
          LPS[j] = 0;
          j++;
        }
      }
    }
  }

  public:
  int minChar(string &s) {
    int size = s.size();

    string reverse_s = s;
    reverse(reverse_s.begin(), reverse_s.end());
    string new_s = s + '#' + reverse_s;

    int new_size = 2 * size + 1;
    vector<int> LPS(new_size);
    computeLPSArray(new_s, new_size, LPS);

    return size - LPS.back();
  }
};
