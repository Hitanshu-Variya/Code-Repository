class Solution {
  public:
  string reverseWords(string s) {
    stringstream ss(s);
    string word;
    stack<string> words;

    while (ss >> word) {
      words.push(word);
    }

    string ans = "";
    while (!words.empty()) {
      string word = words.top();
      words.pop();

      ans += (word + " ");
    }

    ans.pop_back();
    return ans;
  }
};