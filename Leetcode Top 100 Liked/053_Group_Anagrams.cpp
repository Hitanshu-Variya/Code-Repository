class Solution {
  public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> ans;
    unordered_map<string, int> hash_map;
    int index = 0;

    for (auto itr : strs) {
      string original = itr;
      sort(itr.begin(), itr.end());

      if (hash_map.find(itr) == hash_map.end()) {
        ans.push_back({original});
        hash_map[itr] = index++;
      } else
        ans[hash_map[itr]].push_back(original);
    }

    return ans;
  }
};