class Solution {
  public:
  vector<string> AllPossibleStrings(string s) {
    int size = s.size();
    vector<string> ans;
    string str;

    function<void(int, string)> solver = [&](int index, string str) -> void {
      if (index == size) {
        ans.push_back(str);
        return;
      }

      str.push_back(s[index]);
      solver(index + 1, str);
      str.pop_back();

      solver(index + 1, str);
    };

    solver(0, str);
    sort(ans.begin(), ans.end());

    return ans;
  }
};