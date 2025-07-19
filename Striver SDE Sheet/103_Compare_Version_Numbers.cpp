class Solution {
  private:
  vector<int> getNumbers(string s) {
    stringstream ss(s);
    string token;
    vector<int> numbers;

    while (getline(ss, token, '.')) {
      numbers.push_back(stoi(token));
    }

    return numbers;
  }

  public:
  int compareVersion(string version1, string version2) {
    vector<int> number1 = getNumbers(version1);
    vector<int> number2 = getNumbers(version2);

    int size_1 = number1.size(), size_2 = number2.size();
    int limit = max(size_1, size_2);

    for (int i = 0; i < limit; i++) {
      int num1 = (i < size_1) ? number1[i] : 0;
      int num2 = (i < size_2) ? number2[i] : 0;

      if (num1 < num2) return -1;
      if (num1 > num2) return 1;
    }

    return 0;
  }
};