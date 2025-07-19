class Solution {
  private:
  unordered_map<char, int> hash_map = {{'I', 1},   {'V', 5},   {'X', 10}, {'L', 50},  {'C', 100}, {'D', 500}, {'M', 1000}};

  public:
  int romanToInt(string s) {
    int size = s.size();
    int ans = 0;

    for (int i = 0; i < size - 1; i++) {
      ans += (hash_map[s[i]] < hash_map[s[i + 1]]) ? -hash_map[s[i]] : hash_map[s[i]];
    }

    ans += hash_map[s[size - 1]];
    return ans;
  }
};