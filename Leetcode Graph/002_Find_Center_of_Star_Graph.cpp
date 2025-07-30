class Solution {
  public:
  int findCenter(vector<vector<int>> &edges) {
    int size = edges.size();
    vector<int> freq(size + 2, 0);

    for (auto edge : edges) {
      freq[edge[0]]++;
      freq[edge[1]]++;
    }

    for (int i = 0; i < size + 2; i++) {
      if (freq[i] == size) {
        return i;
      }
    }

    return -1;
  }
};