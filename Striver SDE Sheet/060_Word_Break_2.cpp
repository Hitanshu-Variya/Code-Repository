class Solution {
  public:
  vector<string> wordBreak(vector<string> &dict, string &s) {
    int size = s.size();
    vector<string> ans;

    unordered_set<string> set(dict.begin(), dict.end());
    vector<string> path;

    function<void(int)> solver = [&](int index) -> void {
      if (index == size) {
        string sequence = "";
        for (string &str : path) {
          sequence += (str + " ");
        }
        sequence.pop_back();

        ans.push_back(sequence);
        return;
      }

      for (int i = index + 1; i <= size; i++) {
        string substring = s.substr(index, i - index);
        if (set.find(substring) != set.end()) {
          path.push_back(substring);
          solver(i);
          path.pop_back();
        }
      }
    };

    solver(0);
    return ans;
  }
};