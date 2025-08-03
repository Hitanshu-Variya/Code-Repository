class Solution {
  public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> hash_set(wordList.begin(), wordList.end());
    if (hash_set.count(beginWord))
      hash_set.erase(beginWord);

    queue<pair<string, int>> queue;
    queue.push({beginWord, 1});

    while (!queue.empty()) {
      auto [word, level] = queue.front();
      queue.pop();

      if (word == endWord) {
        return level;
      }

      int size = word.size();
      for (int i = 0; i < size; i++) {
        string str = word;

        for (char j = 'a'; j <= 'z'; j++) {
          str[i] = j;

          if (hash_set.count(str)) {
            queue.push({str, level + 1});
            hash_set.erase(str);
          }
        }
      }
    }

    return 0;
  }
};