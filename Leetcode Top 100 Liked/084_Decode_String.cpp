class Solution {
  public:
  string decodeString(string s) {
    int size = s.size();
    stack<string> s1;
    stack<int> s2;

    int num = 0;
    string current = "";
    for (int i = 0; i < size; i++) {
      if (isdigit(s[i])) {
        num = (num * 10) + (s[i] - '0');
      } 
      else if (s[i] == '[') {
        s1.push(current);
        s2.push(num);
        num = 0;
        current = "";
      } 
      else if (s[i] == ']') {
        int num = s2.top();
        s2.pop();
        string prevWord = s1.top();
        s1.pop();

        string decode;
        while (num--) decode += current;
        current = prevWord + decode;
      } 
      else {
        current += s[i];
      }
    }

    return current;
  }
};