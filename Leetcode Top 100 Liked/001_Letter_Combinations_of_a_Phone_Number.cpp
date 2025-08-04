class Solution {
  public:
  vector<string> letterCombinations(string digits) {
    if (digits == "") {
      return vector<string>();
    }

    int size = digits.size();
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;

    function<void(int, string)> solver = [&](int index, string word) -> void {
      if (index == size) {
        ans.push_back(word);
        return;
      }

      for (auto character : mapping[digits[index] - '0']) {
        word.push_back(character);
        solver(index + 1, word);
        word.pop_back();
      }
    };

    solver(0, "");
    return ans;
  }
};