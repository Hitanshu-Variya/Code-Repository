class Solution {
  public:
  bool isAnagram(string s, string t) {
    vector<int> alphabets(26, 0);
    for (auto itr : s)
      alphabets[itr - 'a']++;

    for (auto itr : t)
      alphabets[itr - 'a']--;

    for (auto itr : alphabets)
      if (itr != 0)
        return false;

    return true;
  }
};