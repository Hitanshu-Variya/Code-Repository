class Solution {
  public:
  int maxRepeating(string sequence, string word) {
    int size_1 = sequence.size();
    int size_2 = word.size();

    int ans = 0;
    int length = size_2;
    string newWord = word;

    while (length <= size_1) {
      if (sequence.find(newWord) != string::npos) {
        ans++;
      }

      length += size_2;
      newWord += word;
    }

    return ans;
  }
};