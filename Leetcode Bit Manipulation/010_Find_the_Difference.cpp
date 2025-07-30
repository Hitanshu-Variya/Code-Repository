class Solution {
  public:
  char findTheDifference(string s, string t) {
    int XOR = 0;
    for (auto character : s)
      XOR = XOR ^ character;

    for (auto character : t)
      XOR = XOR ^ character;

    return XOR;
  }
};