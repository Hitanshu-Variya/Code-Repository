class Solution {
  public:
  vector<string> generateParenthesis(int n) {
    vector<string> ans;
    function<void(string, int, int)> solver = [&](string s, int open, int close) -> void {
      if (open == 0 && close == 0) {
        ans.push_back(s);
        return;
      }

      if (open == close) {
        s.push_back('(');
        solver(s, open - 1, close);
      } 
      else if (open == 0) {
        s.push_back(')');
        solver(s, open, close - 1);
      } 
      else if (close == 0) {
        s.push_back('(');
        solver(s, open - 1, close);
      } 
      else {
        s.push_back('(');
        solver(s, open - 1, close);
        s.pop_back();
        s.push_back(')');
        solver(s, open, close - 1);
      }
    };

    solver("", n, n);
    return ans;
  }
};